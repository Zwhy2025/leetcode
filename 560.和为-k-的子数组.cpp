/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

 // @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
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
    int subarraySum(vector<int>& nums, int k)
    {
        vector<int> vPreSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            vPreSum[i + 1] = vPreSum[i] + nums[i];
        }

        int res = 0;
        unordered_map<int, int> map;
        // 假设数组的前缀和数组为prefixSum，
        // 其中prefixSum[i]表示从数组起始位置到第i个位置的元素之和。那么对于任意的两个下标i和j（i < j），
        // 如果prefixSum[j] - prefixSum[i] = k，即从第i个位置到第j个位置的元素之和等于k，
        // 那么说明从第i+1个位置到第j个位置的连续子数组的和为k
        
        // 总结 前缀和之差 表示连续子串和为K
        // 转换解题公式:   prefixSum[i] = prefixSum[j] - k
        for (auto&& it : vPreSum) {
            if (map.find(it - k) != map.end()) {
                res += map[it - k];
            }
            map[it]++;
        }
        return res;
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test560, SimpleTest)
{
    Solution s;
    vector<int> nums = { 1, 2, 3 };
    ASSERT_EQ(2, s.subarraySum(nums, 3));
    nums = { 1, 2, 3 };
    ASSERT_EQ(2, s.subarraySum(nums, 3));
}
