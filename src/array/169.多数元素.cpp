/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
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
    int majorityElement(vector<int>& nums) {
        unordered_multiset<int> set(nums.begin(),nums.end());

        for (auto &&s : set)
        {
            if (set.count(s)>nums.size()/2){
                return s;
            }
        }

        return INT_MIN;
    }
};
// @lc code=end

