# LeetCode 刷题仓库

鸡会留给有准备的人

## 目录结构

```
leetcode/
├── tools/
│   ├── build.sh       # 编译脚本
│   └── pick.py        # 随机选题脚本
├── docs/
│   ├── 题目日志.json
│   └── category_map.json   # 题号 -> 类型映射
├── src/               # 按类型分类的题解
│   ├── array/
│   ├── binary_search/
│   ├── backtrack/
│   ├── dp/
│   ├── tree/
│   ├── linkedlist/
│   ├── stack_queue/
│   ├── hash/
│   ├── sliding_window/
│   ├── greedy/
│   ├── string/
│   └── other/
├── include/
└── CMakeLists.txt
```

## 构建

```bash
./tools/build.sh
```

## 随机选题

```bash
# 指定题号
python3 tools/pick.py 1
python3 tools/pick.py 53

# 从所有题目随机选 2 题
python3 tools/pick.py -n 2

# 从指定类型选题
python3 tools/pick.py --category tree -n 2
python3 tools/pick.py --category dp -n 1

# 清空做题痕迹（只保留题面）并选题
python3 tools/pick.py --reset --category array -n 2
```

支持的类型：`array`, `binary_search`, `backtrack`, `dp`, `tree`, `linkedlist`, `stack_queue`, `hash`, `sliding_window`, `greedy`, `string`, `other`, `all`
