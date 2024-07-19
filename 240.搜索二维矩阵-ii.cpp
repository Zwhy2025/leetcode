/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
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
    bool halfSearch(vector<int>& nums, int target)
    {
        int mid = INT_MAX;
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty()) {
            return false;
        }

        for (int i = 0; i < matrix.size(); i++) {
            // 对每一列二分查找
            if (halfSearch(matrix[i], target)) {
                return true;
            }

        }

        return false;
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test240, Test)
{
    vector<vector<int>> matrix = { { 1, 4, 7, 11, 15 },
                                   { 2, 5, 8, 12, 19 },
                                   { 3, 6, 9, 16, 22 },
                                   { 10, 13, 14, 17, 24 },
                                   { 18, 21, 23, 26, 30 } };
    Solution s;
    EXPECT_EQ(s.searchMatrix(matrix, 5), true);
    EXPECT_EQ(s.searchMatrix(matrix, 20), false);
}