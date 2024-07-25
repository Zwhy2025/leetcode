/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
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

class NumArray {
public:
    vector<int> _vPreSum;
    NumArray(vector<int>& nums)
    {
        _vPreSum.resize(nums.size() + 1, 0);
        for (int i = 1; i < _vPreSum.size(); i++) {
            _vPreSum[i] = _vPreSum[i-1] + nums[i-1];
        }
    }

    int sumRange(int left, int right)
    {
        // 左闭右开
        return _vPreSum[right+1]-_vPreSum[left] ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
 // @lc code=end

#include <gtest/gtest.h>
TEST(Test303, SimpleTest)
{
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray s(nums);
    EXPECT_EQ(s.sumRange(0, 2), 1);
    EXPECT_EQ(s.sumRange(2, 5), -1);
    EXPECT_EQ(s.sumRange(0, 5), -3);
}