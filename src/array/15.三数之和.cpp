/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return res;
            }

            //去重a
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                
                //左右索引指针
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else// 找到符合条件的值
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    //去重bc
                    while(right>left && nums[right]==nums[right-1]) right--;
                    while(right>left && nums[left]==nums[left+1]) left++;

                    right--;
                    left++;
                    
                }
            }
        }
        return res;
    }
};
// @lc code=end
