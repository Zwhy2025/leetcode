// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem704.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
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
#include <memory>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;

        while (begin <= end)
        {
            //int mid = begin + ((end - begin) / 2);
            int mid = (begin + end)/2;

            if (nums[mid] > target)
            {
                end = mid-1;
            }
            else if (nums[mid] < target)
            {
                begin = mid+1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end
