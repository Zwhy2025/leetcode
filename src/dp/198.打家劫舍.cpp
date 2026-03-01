/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
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
    int rob(vector<int>& nums) {
        auto size = nums.size();
        if(size<2){
            return *std::max_element(nums.begin(),nums.end());
        }
        // 求dp[1]其实求的是dp2 
        // 其实可以在状态方程中统一处理
        nums.push_back(0);

        vector<int> dp(size+1,0);
        dp[0]=nums[0];
        dp[1]=std::max(nums[0],nums[1]);

        for (int i = 2; i <= size; i++)
        {
            dp[i] = std::max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[size];
    }
};
// @lc code=end

