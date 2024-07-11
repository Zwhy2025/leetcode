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
        bool swapped = false;
        for (int i = 0; i < nums.size(); i++) {
            bool swapped = false;
            for (int j = i + 1; j < nums.size(); j++) {

                if (nums[i] > nums[j]) {
                    swapped = true;
                    std::swap(nums[i], nums[j]);
                }
            }

            if (!swapped) {
                break;
            }
        }
    }
};
// @lc code=end

#include<gtest/gtest.h>
TEST(test75, test1)
{
    vector<int> nums = { 2,0,2,1,1,0 };
    Solution s;
    s.sortColors(nums);
    vector<int> res = { 0,0,1,1,2,2 };
    EXPECT_EQ(nums, res);
}