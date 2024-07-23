/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
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
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> res(size, 1); ///< 初始化赋值为1,不用对第一个数进行初始化

        // 计算前缀积
        // res[i]存储nums[0]到nums[i-1]的乘积
        for (int i = 1; i < size; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        // 计算后缀积
        // 使用一个临时变量suffix来存储从后向前的累积乘积
        int suffix = 1;
        for (int i = size - 1; i >= 0; i--) {
            res[i] *= suffix;    ///< res[i]乘以从右侧累积的乘积
            suffix *= nums[i];   ///< 更新suffix为当前nums[i]的乘积
        }
        return res;



    }
};
// @lc code=end


#include <gtest/gtest.h>
TEST(Test238, SimpleTest)
{
    Solution s;
    vector<int> in = { 1, 2, 3, 4 };
    vector<int> ans = { 24, 12, 8, 6 };
    ASSERT_EQ(s.productExceptSelf(in), ans);
}