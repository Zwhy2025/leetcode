/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
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
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }

        int up = 1, down = 1;
        //https://leetcode.cn/problems/wiggle-subsequence/solutions/284327/tan-xin-si-lu-qing-xi-er-zheng-que-de-ti-jie-by-lg/

        // 动态规划的影子 := 运行时记录状态,根据上次状态响应
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }

        return std::max(up, down);
    }
};
// @lc code=end

