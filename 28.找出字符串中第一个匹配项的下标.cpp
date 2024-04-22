/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
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
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
        {
            return -1;
        }

        for (size_t i = 0; i < haystack.size(); i++)
        {
            if (i + needle.size() > haystack.size())
            {
                return -1;
            }

            auto begin = haystack.begin() + i;
            if (string(begin, begin + needle.size()) == needle)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
