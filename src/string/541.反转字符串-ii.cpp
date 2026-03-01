/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
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
    string reverseStr(string s, int k)
    {
        // 前进步长2k
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            //进入循环后肯定是字符需要处理的,是保留,还是翻转待定
            // 判断是否包含前段,若有正常翻转
            if (i + k <= s.size()){
                std::reverse(s.begin() + i, s.begin() + i + k);
            }
            else{//字符串少于前段限制,直接翻转剩余
                std::reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

// @lc code=end
