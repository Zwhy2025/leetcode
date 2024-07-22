/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
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
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> dp(cost.size()+1,0);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = std::min(dp[i-1]+cost[i-1] ,dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test746, Test)
{
    Solution s;
    vector<int> cost = { 10, 15, 20 };
    ASSERT_EQ(15, s.minCostClimbingStairs(cost));   

    vector<int> cost1 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    ASSERT_EQ(6, s.minCostClimbingStairs(cost1));

}