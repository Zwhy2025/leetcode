// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // TODO
        std::unordered_map<int, int> mapping;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = mapping.find(target - nums[i]);
            if (it != mapping.end())
            {
                return {it->second, i};
            }
            else
            {
                mapping[nums[i]] = i;
            }
        }

        return {};
    }
};

// @lc code=end
