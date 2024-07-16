/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) {
            return {};
        }
        vector<int> res;
        // 矩阵边界遍历顺序: top,right,bottom,left
        int top = 0;
        int right = matrix[0].size()-1;
        int bottom = matrix.size()-1;
        int left = 0;
        while (res.size() <= matrix[0].size() * matrix.size()) {
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            if (++top > bottom) break;

            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            if (left > --right) break;

            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            if (top > --bottom)break;

            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) break;
        }
        return res;
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(LeetCode54, Solution)
{
    Solution s;
    vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    vector<int> res = s.spiralOrder(matrix);
    vector<int> expect = { 1, 2, 3, 6, 9, 8, 7, 4, 5 };
    EXPECT_EQ(res, expect);
}

