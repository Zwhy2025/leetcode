cmake_minimum_required(VERSION 3.10)

# 项目信息
project(Leetcode)
# 设置编译标志和C++标准
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE ON)

# 常量路径设置
set(PROJECT_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(PROJECT_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)




# 查找和配置GTest
find_package(GTest REQUIRED)
if(GTest_FOUND)
    message(STATUS "GTest found")
    include_directories(${GTest_INCLUDE_DIRS})
    link_directories(${GTest_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "GTest not found")
endif()

# 设置包含目录
include_directories(${PROJECT_INCLUDE_DIR})

# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})

# 添加源文件并创建库
aux_source_directory(. LEETCODE_SRC_FILES)
add_library(leetcode STATIC ${LEETCODE_SRC_FILES})

# 设置目标文件的包含目录
target_include_directories(leetcode PUBLIC ${PROJECT_INCLUDE_DIR})

# 创建可执行文件并链接库
add_executable(display display.cpp)
target_link_libraries(display leetcode)

add_executable(test test.cc)
target_link_libraries(test leetcode ${GTEST_BOTH_LIBRARIES})

# 如果需要，链接pthread
if(UNIX)
    target_link_libraries(test pthread)
endif()
