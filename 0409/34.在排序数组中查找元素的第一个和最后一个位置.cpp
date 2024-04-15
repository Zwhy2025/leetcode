// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem34.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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

    int searchEdge(vector<int>& nums, int target){
        //非递减数列 意思是
        // 可能是有相等元素
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
                return begin;
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = searchEdge(nums,target);
        std::reverse(nums.begin(),nums.end());
        int end = searchEdge(nums,target);
        if(!begin && !end){
            return {begin,int(nums.size()-end)};
        }else{
            return {-1,-1};
        }
    }
};
// @lc code=end

