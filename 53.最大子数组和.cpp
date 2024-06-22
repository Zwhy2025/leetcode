/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
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
    int maxSubArray(vector<int> &nums)
    {
        if(nums.size()<2){
            return nums.back();
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];

        int res = dp[0];
        // dp[i] 的含义是,从原数组开头到以i结尾的子数组的最大值
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i]=std::max(nums[i]+dp[i-1],nums[i]);
            res = dp[i] >res ? dp[i] : res;
        }

        return res;
    }
};
// @lc code=end
