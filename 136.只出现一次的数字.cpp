/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
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
    int singleNumber(vector<int>& nums) {
       unordered_multiset<int> set(nums.begin(),nums.end());
       for (auto &&s : set)
       {    
            if(set.count(s)==1){
                return s;
            }
       }
        return INT_MIN;
    }
};
// @lc code=end

#include "gtest/gtest.h"

TEST(LeetCode136, test1){
    Solution s;
    vector<int> nums = {1,4,2,2,1};
    EXPECT_EQ(s.singleNumber(nums), 4);
}

