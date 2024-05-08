/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
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
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        for (int fast  = 0; fast < nums.size(); fast++)
        {
            if(val!=nums[fast]){
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;
    }
};
// @lc code=end
