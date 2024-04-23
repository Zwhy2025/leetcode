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
        //双指针法（快慢指针法）： 
        //通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
        int show = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            //慢指针才是真正返回的数组
            if (val != nums[fast]){
                nums[show++] = nums[fast];
            }
        }
        return show;
    }
};
// @lc code=end
