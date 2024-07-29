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
    vector<int> _path;
    vector<vector<int>> _res;

    void backtracking(vector<int>& nums, vector<int>& used)
    {
        if (_path.size() == nums.size()) {
            _res.push_back(_path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]){
                used[i]++;
                _path.push_back(nums[i]);
                backtracking(nums, used);
                _path.pop_back();
                used[i]--;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        _res.clear();
        _path.clear();
        vector<int> used(nums.size(), 0);
        backtracking(nums, used);
        return _res;
    }
};
// @lc code=end


#include <gtest/gtest.h>
TEST(LeetCode46, test1)
{
    Solution s;
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> res = s.permute(nums);
    for (auto& v : res) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}