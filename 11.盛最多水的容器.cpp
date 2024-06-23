/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int> &height)
    {
        int res = 0;
        // 双指针
        for (int i = 0, j = height.size() - 1; i < j;)
        {
            int h = std::min(height[i], height[j]);
            int area = h * (j - i);
            // 贪心 距离最远的最有可能最大面积
            res = std::max(area, res);
            if (height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return res;
    }
};
// @lc code=end
