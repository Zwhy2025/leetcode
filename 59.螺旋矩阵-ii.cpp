/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
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
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int target = std::pow(n, 2);///< 目标值
        int idx = 1;                ///< 填充值
        int row = 0, col = 0;       ///< 填充后位置(动态变化)
        int step = n - 1;           ///< 填充为左开右闭区间
        int it = step;              ///< 步长索引
        int mode = 0;               ///< 填充模式
        while (idx <= target) {
            // 每行/列填充 更新步长索引
            it = step;
            if (it == 0) {
                res[row][col] = idx++; //处理奇数居中值
                break;
            } else if (it < 0) {
                break;
            } else {
                while (it--) {
                    switch (mode) {
                    case 0:
                        res[row][col++] = idx++;
                        break;
                    case 1:
                        res[row++][col] = idx++;
                        break;
                    case 2:
                        res[row][col--] = idx++;
                        break;
                    case 3:
                        res[row--][col] = idx++;
                        break;
                    }
                }
                /*
                填充模式:
                1. mode 0: 填充上行从左到右
                2. mode 1: 填充右列从上到下
                3. mode 2: 填充下行从右到左
                4. mode 3: 填充左列从下到上
                完成一轮填充后，更新模式和起始位置
                */
                if (++mode == 4) {
                    step -= 2; // 左右都填充一列，上下都填充一行 所以步长都要减2
                    mode %= 4; // 模式取余
                    row++;     // 完成一轮填充后,回到起始位置
                    col++;     // 起始位置始终处于对角线上
                }
            }
        }
        return res;
    }
};
// @lc code=end

#include<gtest/gtest.h>
TEST(Test_59, test)
{
    Solution s;
    auto res = s.generateMatrix(4);
    for (auto& v : res) {
        for (auto& i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}
