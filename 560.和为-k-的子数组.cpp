/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
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
    int subarraySum(vector<int>& nums, int k) {

        //构造前缀和数组
        vector<int> vfront(nums.size()+1,0);
        for (int i = 0; i < nums.size(); i++)
        {
            vfront[i+1] = vfront[i]+nums[i];
        }
        int res = 0;
        unordered_map<int,int> map;
        // 遍历前缀和
        for(int it : vfront){
            if(map.find(it - k) != map.end()){
                // 隐含了一个信息,第一次遍历时
                // 前缀和为0,会使得map[0] = 1
                // 后续会记录前缀和 
                // 如果有前缀和 能与 it-k 相等
                // 说明这两个前缀和之间的子数组和为k
                // 也符合题意
                // 这也太tm巧妙了
                res += map[it-k];
            }
            map[it]++;
        }
        return res;
    }
};
// @lc code=end

#include <gtest/gtest.h>
#include "log.h"
TEST(Test560, SimpleTest){
    vector<int> nums = {1,1,1};
    int k = 2;
    Solution s;
    int res = s.subarraySum(nums, k);
    int expect = 2;
    EXPECT_EQ(res, expect);
}
