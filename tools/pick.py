#!/usr/bin/env python3
"""
随机选题脚本：支持按类型选题，可选清空做题痕迹（只保留题面）。
支持 positional 参数指定题号。
"""
import os
import re
import json
import random
import argparse
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
SRC_DIR = PROJECT_ROOT / "src"
DOCS_DIR = PROJECT_ROOT / "docs"
LOG_FILE = DOCS_DIR / "题目日志.json"
CATEGORY_MAP_FILE = DOCS_DIR / "category_map.json"

CATEGORIES = [
    "array", "binary_search", "backtrack", "dp", "tree", "linkedlist",
    "stack_queue", "hash", "sliding_window", "greedy", "string", "other"
]


def load_category_map():
    """加载题号 -> 类型映射"""
    if not CATEGORY_MAP_FILE.exists():
        return {}
    with open(CATEGORY_MAP_FILE, "r", encoding="utf-8") as f:
        return json.load(f)


def get_questions_by_category(category: str) -> list[str]:
    """根据分类获取题目文件名列表"""
    if category == "all":
        files = []
        for cat_dir in SRC_DIR.iterdir():
            if cat_dir.is_dir() and cat_dir.name in CATEGORIES:
                for f in cat_dir.glob("*.cpp"):
                    files.append(f.name)
        return files

    cat_dir = SRC_DIR / category
    if not cat_dir.exists() or not cat_dir.is_dir():
        return []
    return [f.name for f in cat_dir.glob("*.cpp")]


def get_file_path(filename: str) -> Path | None:
    """根据文件名找到完整路径（在 src 子目录中）"""
    for cat_dir in SRC_DIR.iterdir():
        if cat_dir.is_dir():
            p = cat_dir / filename
            if p.exists():
                return p
    return None


def find_file_by_question_id(question_id: str) -> str | None:
    """根据题号查找文件名，如 1 -> 1.两数之和.cpp，3110 -> 3110.字符串的分数.cpp"""
    prefix = str(question_id) + "."
    for cat_dir in SRC_DIR.iterdir():
        if cat_dir.is_dir():
            for f in cat_dir.glob("*.cpp"):
                if f.name.startswith(prefix):
                    return f.name
    return None


def extract_code_block(content: str) -> str:
    """提取 @lc code=start 到 @lc code=end 之间的内容"""
    start_marker = "// @lc code=start"
    end_marker = "// @lc code=end"
    start_idx = content.find(start_marker)
    end_idx = content.find(end_marker)
    if start_idx == -1 or end_idx == -1:
        return content
    block_start = start_idx + len(start_marker)
    return content[block_start:end_idx].strip()


def clear_implementation(content: str) -> str:
    """
    清空函数体实现，只保留 class Solution 与函数签名。
    将每个函数体替换为 { // TODO }
    """
    result = []
    i = 0
    n = len(content)

    while i < n:
        # 查找 ) 后跟 { 的模式（函数定义）
        match = re.search(r"\)\s*\{", content[i:], re.DOTALL)
        if not match:
            result.append(content[i:])
            break

        pos = i + match.start()
        end_pos = i + match.end()
        result.append(content[i:end_pos])

        # 从 { 开始找匹配的 }
        brace_start = end_pos - 1  # position of {
        depth = 1
        j = end_pos
        while j < n and depth > 0:
            if content[j] == "{":
                depth += 1
            elif content[j] == "}":
                depth -= 1
            j += 1

        # 替换函数体为 // TODO
        result.append("\n        // TODO\n    }")
        i = j
    return "".join(result)


def reset_file_to_template(filepath: Path) -> None:
    """将文件清空为只保留题面（函数签名），清空实现"""
    content = filepath.read_text(encoding="utf-8")
    start_marker = "// @lc code=start"
    end_marker = "// @lc code=end"
    start_idx = content.find(start_marker)
    end_idx = content.find(end_marker)
    if start_idx == -1 or end_idx == -1:
        return

    before = content[: start_idx + len(start_marker)]
    block = content[start_idx + len(start_marker) : end_idx]
    after = content[end_idx:]

    cleared_block = clear_implementation(block)
    new_content = before + "\n" + cleared_block + "\n" + after
    filepath.write_text(new_content, encoding="utf-8")


def read_log() -> dict:
    """读取题目日志"""
    if not LOG_FILE.exists():
        return {"questions": [], "recent": {}}
    with open(LOG_FILE, "r", encoding="utf-8") as f:
        return json.load(f)


def write_log(log: dict) -> None:
    """写入题目日志"""
    LOG_FILE.parent.mkdir(parents=True, exist_ok=True)
    with open(LOG_FILE, "w", encoding="utf-8") as f:
        json.dump(log, f, ensure_ascii=False, indent=4)


def main():
    parser = argparse.ArgumentParser(description="随机选择 LeetCode 题目")
    parser.add_argument(
        "question",
        nargs="?",
        help="指定题号，如 1、53、3110",
    )
    parser.add_argument(
        "--category", "-c",
        choices=CATEGORIES + ["all"],
        default="all",
        help="题目类型分类",
    )
    parser.add_argument(
        "-n",
        type=int,
        default=2,
        help="选题数量",
    )
    parser.add_argument(
        "--reset",
        action="store_true",
        help="清空做题痕迹：只保留题面，清空实现代码",
    )
    args = parser.parse_args()

    if args.question is not None:
        # 指定题号模式
        filename = find_file_by_question_id(str(args.question))
        if not filename:
            print(f"未找到题号 {args.question} 对应的题目")
            return
        selected = [filename]
    else:
        # 随机选题模式
        questions = get_questions_by_category(args.category)
        if not questions:
            print(f"分类 {args.category} 下没有题目")
            return
        selected = random.sample(questions, min(args.n, len(questions)))

    if args.reset:
        for q in selected:
            fp = get_file_path(q)
            if fp:
                reset_file_to_template(fp)
                print(f"[已清空] {q}")
            else:
                print(f"[未找到] {q}")

    print("\n今日题目:")
    for q in selected:
        print(f"  - {q}")
        fp = get_file_path(q)
        if fp:
            content = fp.read_text(encoding="utf-8")
            code = extract_code_block(content)
            print("---")
            print(code)
            print("---")


if __name__ == "__main__":
    main()
