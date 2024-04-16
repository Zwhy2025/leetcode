/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
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
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        while (begin<=end)
        {
            auto mid = (begin+end)/2;
            if(nums[mid]>target){
                end = mid -1;
            }else if (nums[mid]<target){
                begin =mid +1;
            }else{
                return mid;
            }
        }

        return end+1;
    }
};
// @lc code=end

