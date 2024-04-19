/*
 * @lc app=leetcode.cn id=3110 lang=cpp
 *
 * [3110] 字符串的分数
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
    int scoreOfString(string s)
    {
        int res = 0;
        // 保证 s.size() - 2有意义
        if (s.size() < 2)
        {
            return res;
        }
        // 遍历+强制类型转换
        for (int i = 0; i <= s.size() - 2; i++)
        {
            res += std::abs(int(s[i] - s[i + 1]));
        }
        return res;
    }
};
// @lc code=end
