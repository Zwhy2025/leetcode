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
