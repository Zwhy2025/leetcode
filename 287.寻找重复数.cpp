/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
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
    int findDuplicate(vector<int>& nums)
    {
        unordered_map<int, bool> map;
        for (auto&& num : nums) {
            if (map[num]) {
                return num;
            }
            map[num] = true;

        }
        return INT_MIN;
    }
};
// @lc code=end

