/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        int slow=0;

        for (int fast =0; fast < nums.size(); fast++)
        {
            if(nums[fast]!=0){
                swap(nums[slow],nums[fast]);
                slow++;
            }
        }
    }
};
// @lc code=end

