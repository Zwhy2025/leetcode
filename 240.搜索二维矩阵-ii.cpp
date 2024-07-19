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


    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int itRow = 0;
        int itCol = colSize - 1;

        while (itRow < rowSize && itCol >= 0) {
            if (matrix[itRow][itCol] == target) {
                return true;
            } else if ((matrix[itRow][itCol] > target)) {
                itCol--;
            } else {
                itRow++;
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
    EXPECT_EQ(s.searchMatrix(matrix, 20), false);
}