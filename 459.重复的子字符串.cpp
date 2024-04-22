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
        for (int i = 1;  i * 2 <= s.size(); i++)
        {
            if (s.size() % i == 0)
            {
                bool match = true;
                for (int j = i; j < s.size(); j++)
                {
                    // 找到前i个位置进行匹配
                    // 并且j向后移动 
                    // 滑动匹配
                    if (s[j] != s[j - i])
                    {
                        match = false;
                        break;
                    }
                }

                if (match) return true;
            }
        }

        return false;
    }
};
// @lc code=end
