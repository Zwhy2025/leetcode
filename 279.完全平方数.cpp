/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
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
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // 这是人能想的出来的 ???
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
// @lc code=end

