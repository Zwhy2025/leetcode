/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
    vector<vector<int>> _ret;
    vector<int> _path;
    void backtracking(vector<int>& nums,int startIndex){
        // 子集问题 = 收集所有节点,而不是只有叶子节点
        _ret.push_back(_path);

        for(int  i = startIndex; i < nums.size(); i++)
        {
          _path.push_back((nums[i]));
          backtracking(nums,i+1);
          _path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        _ret.clear();
        _path.clear();
        backtracking(nums,0);
        return _ret;
    }
};
// @lc code=end

