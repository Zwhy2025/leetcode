/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int index = k % nums.size();

        std::reverse(nums.begin(),nums.end());

        std::reverse(nums.begin(),nums.begin()+index);

        std::reverse(nums.begin()+index,nums.end());
    }
};
// @lc code=end

