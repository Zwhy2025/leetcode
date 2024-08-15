/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

 // @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> _res;
    string _path;

    void backtracking(int n, int l, int r) {

        // 不仅仅是减枝,还确保逻辑
        if (l > n || l < r) {
            // 只在序列仍然保持有效时才添加 ‘(’ 或 ‘)’
            return;
        }

        if (_path.size() == n * 2) {
            _res.push_back(_path);
            return;
        }

        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                _path.push_back('(');
                backtracking(n, l + 1, r);
            }
            else {
                _path.push_back(')');
                backtracking(n, l, r + 1);
            }
            _path.pop_back();
        }

    }


    vector<string> generateParenthesis(int n) {
        _res.clear();
        _path.clear();
        this->backtracking(n, 0, 0);
        return _res;

    }
};
// @lc code=end

#include<gtest/gtest.h>

TEST(LeetCode22, test1) {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (auto& str : res) {
        cout << str << endl;
    }
}