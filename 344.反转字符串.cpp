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
    void swap(char& a, char& b)
    {
        auto temp = a;
        a = b;
        b = temp;
    }

    void reverseString(vector<char> &s)
    {

        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            this->swap(s[i],s[j]);
        }
    }
};
// @lc code=end
