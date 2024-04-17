/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
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
    void reverseString(vector<char> &s)
    {
        char tmp;
        // 双指针
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            //交换
            tmp  = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
};
// @lc code=end
