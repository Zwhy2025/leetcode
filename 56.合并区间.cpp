/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.empty()) return {};

        std::sort(intervals.begin(),intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (auto && interval : intervals)
        {
            if(interval[0]<=merged.back()[1]){
                merged.back()[1] = max(merged.back()[1],interval[1]);
            }else{
                merged.push_back((interval));
            }
        }
        return merged;
    }
};
// @lc code=end

