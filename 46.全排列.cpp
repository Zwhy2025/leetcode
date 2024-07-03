/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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

    vector<vector<int>> _res;
    vector<int> _path;
    
    void backtracking(vector<int>& nums, vector<bool>& used)
    {
        if (_path.size() == nums.size()) {
            _res.push_back(_path);
        }

        for (int i = 0; i < nums.size(); i++) {
            // 登记used数组在每次深度遍历时候不使用重复元素
            // 而旁系叶子节点不被used影响,因为已经回溯
            if (used[i] == true) continue;

            used[i] = true;
            _path.push_back(nums[i]);
            backtracking(nums, used);
            _path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        _path.clear();
        _res.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return _res;
    }
};
// @lc code=end

