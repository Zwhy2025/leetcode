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
    vector<int> _vnPath;
    vector<vector<int>> _vnRes;

    void backtracking(vector<int>& nums, int startIndex)
    {
        _vnRes.push_back(_vnPath);
          
        for (int i = startIndex; i < nums.size(); i++)
        {   
            _vnPath.push_back(nums[i]);
            backtracking(nums, i + 1);
            _vnPath.pop_back();
        }   
        
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        _vnRes.clear();
        _vnPath.clear();

        backtracking(nums, 0);
        return _vnRes;
    }
};
// @lc code=end


#include <gtest/gtest.h>
TEST(Test78, Test)
{
    vector<int> nums = { 1, 2, 3 };
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    
    vector<vector<int>> expected = {
        { 3 },
        { 1 },
        { 2 },
        { 1, 2, 3 },
        { 1, 3 },
        { 2, 3 },
        { 1, 2 },
        {}
    };
    EXPECT_EQ(res, expected);
}