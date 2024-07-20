/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
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
    bool halfSearch(vector<int>& nums, int target)
    {
        int mid = INT_MAX;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid]>target) {
                end = mid - 1;
            } else if (nums[mid]<target) {
                start = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) {
            return  false;
        }

        for (auto&& nums : matrix) {
            if (this->halfSearch(nums, target)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


#include <gtest/gtest.h>
TEST(Test74, Test)
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    Solution s;
    EXPECT_EQ(s.searchMatrix(matrix, 3), true);
    EXPECT_EQ(s.searchMatrix(matrix, 13), false);
}