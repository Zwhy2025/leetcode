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
        int n =cost.size();
        cout<<"n: "<<n<<endl;
        if (n<3)
        {
             return std::min(*cost.begin(),cost.back());
        }
        
        vector<int> dp(n+1);
        dp[1]=0;
        dp[2]=std::min(cost[0],cost[1]);
        
        for (int i = 3; i <= n; i++)
        {    
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
    
        return dp[n];
    }
};
// @lc code=end

