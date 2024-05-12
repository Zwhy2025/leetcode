/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
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

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 数组需要检索的大小有 1-nums.size()
        vector<int> sums;
        for (int i = nums.size(); i > 0; i--){
            //std::cout <<"i: "<< i << std::endl;
            for (int j = 0; j < nums.size(); j++){
                //std::cout <<"j: "<< j << std::endl;
                //std::cout <<"sum: "<< sum << std::endl;
                sums.emplace_back(std::accumulate(j+nums.begin(),j+nums.begin()+i,0));
                if ((j + nums.begin() + i) == nums.end()){
                    break;
                }
            }
        }
        return *std::max_element(sums.begin(), sums.end());
    }
};
// @lc code=end
