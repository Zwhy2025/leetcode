/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstring>
#include <cassert>
#include <numeric>
#include <memory>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // 右值节省内存
        // 从1开始查找,忽略查到left s
        // 查到right s
        // 则为中间一定有repeated
        return (s + s).find(s, 1) != s.size();
    }
};
// @lc code=end

