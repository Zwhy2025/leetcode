/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
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
    vector<string> _vRes;
    string _strPath;
    void _backtracking(int n, int l, int r)
    {
        if (l > n || l < r) { // 剪枝
            return;///< 这是这题的精髓,本质上回溯就是枚举,然后剪枝不符合条件的
        }

        if (_strPath.size() == 2 * n) {
            _vRes.push_back(_strPath);
            return;
        }

        // 意识到括号匹配就是二进制,进行交替打印
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                _strPath.push_back('(');
                _backtracking(n, l + 1, r);
            } else {
                _strPath.push_back(')');
                _backtracking(n, l, r + 1);

            }
            _strPath.pop_back();
        }

    }

    vector<string> generateParenthesis(int n)
    {
        _vRes.clear();
        _strPath.clear();
        _backtracking(n, 0, 0);
        return  _vRes;
    }
};
// @lc code=end

