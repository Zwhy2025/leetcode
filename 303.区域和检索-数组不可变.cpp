/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
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

class NumArray {
public:
    vector<int> _vSums;
    NumArray(vector<int>& nums) {
        _vSums.resize(nums.size()+1,0);

        for (int i = 0; i < nums.size(); i++){
            _vSums[i+1]=_vSums[i]+nums[i];
        }
        
    }
    
    int sumRange(int left, int right) {

        return _vSums[right+1]-_vSums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

