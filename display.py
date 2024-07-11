import os
import random
import json
from datetime import datetime, timedelta
import argparse

# 可调整的参数
QUESTION_LOG_FILE = "题目日志.json"
DAYS_LIMIT = 10  # 十天内不重复
QUESTIONS_PER_RUN = 2  # 每次运行选择的题目数量

def get_question_list():
    # 获取当前目录下符合 "xx.k-个一组翻转链表.cpp" 格式的文件
    questions = [f for f in os.listdir() if f.endswith(".cpp") and f[0].isdigit()]
    return questions

def read_log_file():
    # 读取日志文件
    if os.path.exists(QUESTION_LOG_FILE):
        with open(QUESTION_LOG_FILE, "r", encoding='utf-8') as file:
            return json.load(file)
    return {"questions": [], "recent": {}}

def write_log_file(log):
    # 写入日志文件
    with open(QUESTION_LOG_FILE, "w", encoding='utf-8') as file:
        json.dump(log, file, ensure_ascii=False, indent=4)

def clean_old_log(log):
    # 删除超过DAYS_LIMIT天的缓存
    now = datetime.now()
    print(f"当前时间: {now}")
    time_limit = now - timedelta(days=DAYS_LIMIT)
    log["recent"] = {k: v for k, v in log["recent"].items() if datetime.strptime(v, '%Y-%m-%d %H:%M:%S') >= time_limit}
    return log

def update_question_log(log, selected_questions):
    # 更新日志文件
    now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    for question in selected_questions:
        log["recent"][question] = now
    write_log_file(log)

def select_questions(questions, log, num_questions):
    # 随机选择num_questions道题目
    now = datetime.now()
    time_limit = now - timedelta(days=DAYS_LIMIT)
    available_questions = [q for q in questions if datetime.strptime(log["recent"].get(q, '1970-01-01 00:00:00'), '%Y-%m-%d %H:%M:%S') < time_limit]

    if len(available_questions) < num_questions:
        raise Exception("没有足够的题目可以选择")

    selected_questions = random.sample(available_questions, num_questions)
    update_question_log(log, selected_questions)

    return selected_questions

def main():
    parser = argparse.ArgumentParser(description="选择LeetCode题目")
    parser.add_argument("-n", type=int, default=QUESTIONS_PER_RUN, help="每次运行选择的题目数量")
    args = parser.parse_args()

    # 读取题目列表和日志文件
    questions = get_question_list()
    log = read_log_file()
    
    # 输出日志信息
    print("\n当前日志信息:")
    print(json.dumps(log, ensure_ascii=False, indent=4))
    
    # 输出当前题库数量
    print(f"当前题库数量: {len(questions)}")

    # 清理超过DAYS_LIMIT天的缓存
    log = clean_old_log(log)

    # 输出新增的题目
    new_questions = [q for q in questions if q not in log["questions"]]
    if new_questions:
        log["questions"].extend(new_questions)
        print("\n新增的题目:")
        for question in new_questions:
            print(question)
    else:
        print("\n没有新增的题目.")

    # 随机选择num_questions道题目并更新日志
    try:
        selected_questions = select_questions(questions, log, args.n)
        print("\n今日leetcode题目:")
        for question in selected_questions:
            print(question)
    except Exception as e:
        print(f"\n错误: {e}")

if __name__ == "__main__":
    main()