/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> item(i + 1, 1);
            // 剪枝
            if (i > 1) {
                for (int j = 1; j < item.size() - 1; j++) {
                    item[j] = res.back()[j - 1] + res.back()[j];
                }
            }
            res.push_back(item);
        }
        return res;
    }
};
// @lc code=end
