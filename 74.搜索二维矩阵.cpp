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

    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) {
            return  false;
        }

        int rowNums = matrix.size();
        int colNums = matrix[0].size();

        // 从左下角开始往上查找
        int itRow = rowNums - 1, itCol = 0;

        while (itCol < colNums && itRow >= 0) {
            if (matrix[itRow][itCol] > target) {
                itRow--;// 先找到所在元素的行
            } else if (matrix[itRow][itCol] < target) {
                itCol++;// 先找到所在元素的列
            } else {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end


#include <gtest/gtest.h>
TEST(Test74, SimpleTest)
{
    Solution solution;
    vector<vector<int>> vec = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    EXPECT_EQ(solution.searchMatrix(vec, 3), true);
    EXPECT_EQ(solution.searchMatrix(vec, 13), false);
}