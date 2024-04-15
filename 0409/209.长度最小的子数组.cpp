/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
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
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
       auto it = nums.begin();
       for (int i = 1; i <= nums.size(); i++)
       {
         

           int sum = std::accumulate(it, it+i, 0);
           if(sum>=target){
             return i; 
           }

       }
       
    }
};
// @lc code=end

