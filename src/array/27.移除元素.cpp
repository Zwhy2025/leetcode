/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
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
#include <memory>
#include <numeric>
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
  int removeElement(vector<int> &nums, int val)
  {
    // TODO

    std::vector<int> ret;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != val)
      {
        ret.push_back(nums[i]);
      }
    }
    nums = ret;
    return nums.size();
  }
};

// @lc code=end
