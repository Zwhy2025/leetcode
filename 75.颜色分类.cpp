/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
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
    void selectSorting(vector<int>& nums)
    {
        //选择排序
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // 进行n次循环,每次循环比较n到1次,将最小的元素选择出来
                if (nums[j] < nums[i]) {
                    std::swap(nums[j], nums[i]);
                }

            }

        }
    }

    void bubbleSorting(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++) {
            bool isSwap = false;
            for (int j = 1; j < nums.size()-1; j++) {
                if (nums[j - 1] > nums[j]) {
                    isSwap = true;
                    std::swap(nums[j - 1], nums[j]);
                }
            }
            if (!isSwap) {
                break;
            }

        }
    }

    void sortColors(vector<int>& nums)
    {
        this->bubbleSorting(nums);
    }
};
// @lc code=end

#include <gtest/gtest.h>

TEST(Test75, Test1)
{
    vector<int> nums = { 2,0,2,1,1,0 };
    Solution s;
    s.sortColors(nums);
    vector<int> res = { 0,0,1,1,2,2 };
    EXPECT_EQ(nums, res);
}