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

class Solution {
public:
    int scoreOfString(string s)
    {
        int score = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            score += std::abs(int(s[i + 1] - s[i]));
        }
        return score;
    }
};
// @lc code=end

