/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX,profit = 0;
        
        // 记住最小的价格,然后每次与当前的价格进行比较
        // 并记录最高的价格差
        for (auto &&price : prices)
        {
            cost = std::min(cost,price);
            profit = max(profit,price- cost);
        }
        return profit;
    }
};
// @lc code=end

