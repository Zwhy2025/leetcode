/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
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
    void rotate(vector<int>& nums, int k) {
        
        k %= nums.size();
        if(k==0) return;
        
        /// 反转整个数组
        reverse(nums.begin(), nums.end());
        // 反转前 k 个元素
        reverse(nums.begin(), nums.begin() + k);
        // 反转剩余的元素
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

