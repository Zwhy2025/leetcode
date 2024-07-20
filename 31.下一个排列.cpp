/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
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
    void nextPermutation(vector<int>& nums)
    {
        // 从后往前找到第一个递减的元素
        int left = nums.size() - 2;
        while (left >= 0 && nums[left] >= nums[left + 1]) {
            left--;
        }
        //  如果找到了递减的元素，那么从后往前找到第一个比它大的元素，交换位置
        //  因为判断成功递减的前一个元素,并不一定是刚刚好比它大的元素
        if (left >= 0) {
            int right = nums.size() - 1;
            while (right >= 0 && nums[right] <= nums[left]) {
                right--;
            }
            std::swap(nums[left], nums[right]);
        }
        // 尽在不言中
        std::reverse(nums.begin()+left+1, nums.end());

    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test31, SimpleTest)
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.nextPermutation(nums);
    vector<int> res = {1, 3, 2};
    ASSERT_EQ(nums, res);
}