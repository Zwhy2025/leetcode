/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

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

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++) {

            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    std::swap(nums[i], nums[j]);
                }

            }

        }
    }
};
// @lc code=end

#include<gtest/gtest.h>
TEST(test75, test1)
{
    vector<int> nums = { 0, 2, 1, 2, 0 };
    Solution s;
    s.sortColors(nums);
    vector<int> res = { 0, 0, 1, 2, 2 };
    EXPECT_EQ(nums, res);
}