/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
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
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end){
            std::swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        k %= nums.size();
        if (k == 0)
            return;

        /// 反转整个数组
        this->reverse(nums, 0, size - 1);
        // 反转前 k 个元素
        this->reverse(nums, 0, k - 1);
        // 反转剩余的元素
        this->reverse(nums, k, size - 1);
    }
};
// @lc code=end
