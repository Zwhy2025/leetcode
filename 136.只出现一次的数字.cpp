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
        int res = 0;
        // 两个相同的值进行 ^ 运算得到0
        // 连续 ^ 只会得到出现一次的数字 ^_^
        for (int i = 0; i < nums.size(); i++){
            res^=nums[i];
        }
        return res;
    }
};
// @lc code=end

#include "gtest/gtest.h"

TEST(LeetCode136, test1){
    Solution s;
    vector<int> nums = {1,4,2,2,1};
    EXPECT_EQ(s.singleNumber(nums), 4);
}

