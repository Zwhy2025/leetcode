/**
 * @file log.h
 * @brief 一个简单的日志系统，支持异步写入文件，控制台输出颜色等功能
 * @date 2024-06-22
 * @version 1.0
 * @note 使用方法：
 * 1. 在main函数开始前调用INIT_LOG()初始化日志系统,
 *    注意传入日志等级,如果不需要输入文件可以不传入文件名
 * 2. 使用LOG_'level' << message 记录日志
 * 3. level有四种：DBUG, INFO, WARN, EROR 
 */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <queue>
#include <thread>  
#include <condition_variable>  

// 定义日志级别
enum class LogLevel {
    DBUG,     // 调试
    INFO,     // 信息
    WARN,     // 警告
    EROR,     // 错误
};

// 定义控制台颜色代码
enum class ConsoleColor {
    DEFAULT = 0,
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

class LogException : public std::exception {
private:
    std::string message;
public:
    LogException(const std::string& msg) : message(msg) {}
    
    // 重写 what() 方法以返回异常消息
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class ConsoleColorSetter {
public:
    // 设置控制台输出颜色,使用RAII机制进行设置和重置
    ConsoleColorSetter(ConsoleColor color) {
        std::ostringstream oss;
        oss << "\033[" << static_cast<int>(color) << "m";
        _strColorCode = oss.str();
    }

    ~ConsoleColorSetter() {
        _resetColor();
    }

    friend std::ostream& operator<<(std::ostream& os, const ConsoleColorSetter& colorSetter) {
        os << colorSetter._strColorCode;
        return os;
    }
private:

    void _resetColor() {
        std::cout << "\033[0m"; // 重置颜色
    }

private:
    std::string _strColorCode;
};


class Logger {
public:
    // 获取Logger的单例实例
    static Logger& getInstance() {
        static Logger _tInstance;
        return _tInstance;
    }

    // 初始化日志等级,日志文件,并启动异步处理线程
    void init(LogLevel level, const std::string& filename) {
        _setLogLevel(level);
        _setLogFile(filename);

        // 启动后台处理线程
        _bStopThread = false;
        _tAsyncThread = std::thread(&Logger::_processLogQueue, this);
    }

    // 记录日志
    void log(LogLevel level, const std::string& message, const char* file, const char* func, int line) {
        
        if (_bStopThread)
        {
            //抛出异常未初始化
            throw LogException("Logger has not been initialized");
        }
        
        if (level >= _eLogLevel) {
            std::lock_guard<std::mutex> guard(_tMutex);
            _LogQueue.push(std::make_tuple(level, message, file, func, line));
            _tLogQueueCondition.notify_one(); // 唤醒后台线程
        }
    }

    // 停止日志系统
    void shutdown() {
        {
            std::lock_guard<std::mutex> guard(_tMutex);
            _bStopThread = true;
        }
        _tLogQueueCondition.notify_one();   // 唤醒后台线程
        _tAsyncThread.join();               // 等待后台线程结束
    }

private:

    // 私有构造函数和析构函数，确保单例模式
    Logger() : _eLogLevel(LogLevel::INFO), _eConsoleColorThreshold(LogLevel::WARN) {}
    ~Logger() {
        if (_tFileStream.is_open()) {
            _tFileStream.close();
        }
    }

    // 禁止拷贝和赋值
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // 将日志级别转换为字符串
    std::string _logLevelToString(LogLevel level) {
        switch (level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARN: return "WARN";
        case LogLevel::EROR: return "EROR";
        case LogLevel::DBUG: return "DBUG";
        default: return "UNKNOWN";
        }
    }

    // 设置日志级别
    void _setLogLevel(LogLevel level) {
        _eLogLevel = level;
    }

    // 设置日志文件
    void _setLogFile(const std::string& filename) {
        std::lock_guard<std::mutex> guard(_tMutex); // 线程安全

        if (_tFileStream.is_open()) {
            _tFileStream.close();
        }
        _tFileStream.open(filename, std::ios::out | std::ios::app);
        if (!_tFileStream) {
            //std::cerr << "Failed to open log file: " << filename << std::endl;
        }
    }

    // 生成日志信息字符串
    std::string _formatLogMessage(LogLevel level, const std::string& message, const char* file, const char* func, int line) {
        auto now = std::chrono::system_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
        auto s = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();

        std::tm* tm = std::localtime(&s);

        std::ostringstream oss;
        oss << "[" << std::put_time(tm, "%Y-%m-%d %H:%M:%S") << "." << std::setfill('0') << std::setw(3) << ms.count() << "] ";
        oss << "[" << _logLevelToString(level) << "]: " << message;
        oss << " (" << _extractFilename(file) << " " << func << ":" << line << ")" << std::endl;

        return oss.str();
    }

    // 一个简单的函数，用于从路径中提取文件名
    std::string _extractFilename(const char* filePath) {
        const char* filename = filePath;
        const char* ptr = filePath;

        while (*ptr) {
            if (*ptr == '/' || *ptr == '\\') {
                filename = ptr + 1; // 文件名是路径中最后一个'/'或'\'之后的字符串
            }
            ptr++;
        }

        return filename;
    }

    // 后台线程处理函数
    void _processLogQueue() {
        while (!_bStopThread) {
            std::unique_lock<std::mutex> lock(_tMutex);
            _tLogQueueCondition.wait(lock, [this]() { return _bStopThread || !_LogQueue.empty(); });

            while (!_LogQueue.empty()) {
                auto logEntry = _LogQueue.front();
                _LogQueue.pop();
                lock.unlock(); // 在写入日志时释放锁

                std::string logMessage = _formatLogMessage(std::get<0>(logEntry), std::get<1>(logEntry), std::get<2>(logEntry), std::get<3>(logEntry), std::get<4>(logEntry));

                if (_tFileStream.is_open()) {
                    _tFileStream << logMessage;
                    _tFileStream.flush(); // 立即刷新文件流
                }

                // 输出到控制台
                std::ostringstream coloredMessage;
                switch (std::get<0>(logEntry)) {
                    case LogLevel::DBUG:
                        coloredMessage << ConsoleColorSetter(ConsoleColor::GREEN);
                        break;
                    case LogLevel::INFO:
                        coloredMessage << ConsoleColorSetter(ConsoleColor::DEFAULT);
                        break;
                    case LogLevel::WARN:
                        coloredMessage << ConsoleColorSetter(ConsoleColor::YELLOW);
                        break;
                    case LogLevel::EROR:
                        coloredMessage << ConsoleColorSetter(ConsoleColor::RED);
                        break;
                    default:
                        break;
                }
                coloredMessage << logMessage;
                coloredMessage << ConsoleColorSetter(ConsoleColor::DEFAULT);
                std::cout << coloredMessage.str();

                lock.lock(); // 重新获取锁
            }
        }
    }

 private:
    bool _bStopThread = true;                           // 标记是否停止后台线程
    std::mutex _tMutex;                          // 互斥量，保证线程安全
    LogLevel _eLogLevel;                         // 日志级别
    std::thread _tAsyncThread;                   // 后台处理线程
    std::ofstream _tFileStream;                  // 文件流
    LogLevel _eConsoleColorThreshold;            // 控制台输出颜色的阈值
    std::condition_variable _tLogQueueCondition; // 条件变量，用于通知日志队列的状态变化
    std::queue<std::tuple<LogLevel, std::string, const char*, const char*, int>> _LogQueue; // 日志消息队列
};

// 用于日志流操作的类
class LogStream {
public:
    LogStream(LogLevel level, const char* file, const char* func, int line)
        : _tLevel(level), _strFilePath(file), _strFuncName(func), _nLine(line) {}

    ~LogStream() {
        Logger::getInstance().log(_tLevel, _tStream.str(), _strFilePath, _strFuncName, _nLine);
    }

    template<typename T>
    LogStream& operator<<(const T& value) {
        _tStream << value;
        return *this;
    }

private:
    LogLevel _tLevel;
    const char* _strFilePath;
    const char* _strFuncName;
    int _nLine;
    std::ostringstream _tStream;
};


class LogInit {
public:
    LogInit(LogLevel level= LogLevel::DBUG, const std::string& filename= "") {
        Logger::getInstance().init(level, filename);
    }
    
    ~LogInit() {
        Logger::getInstance().shutdown();
    }
};

#define LOG(level) LogStream(level, __FILE__, __func__, __LINE__)
#define LOG_DBUG LOG(LogLevel::DBUG)
#define LOG_INFO LOG(LogLevel::INFO)
#define LOG_WARN LOG(LogLevel::WARN)
#define LOG_EROR LOG(LogLevel::EROR)

#define INIT_LOG(...) LogInit log(__VA_ARGS__)