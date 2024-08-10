/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
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

class Solution
{
public:
    vector<vector<int>> _res;
    vector<int> _path;

    void backtracking(int n, int k, int index)
    {
        if (_path.size() == k){
            _res.push_back(_path);
            return;
        }

        for (int i = index; i <= n; i++){
            _path.push_back(i);
            backtracking(n, k, i + 1);
            _path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        _res.clear();
        _path.clear();
        backtracking(n, k, 1);
        return _res;
    }
};
// @lc code=end
