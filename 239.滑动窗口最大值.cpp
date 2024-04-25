/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        
        if (nums.size()<k){
            return res;
        }
        // 耗时 O(n*M)
        // 暴力过不了 会超时
        for (auto it = nums.begin(); it <= nums.end()-k; it++)
        {   
            res.push_back(*std::max_element(it,it+k));
        }
        return res;
    }
};
// @lc code=end

