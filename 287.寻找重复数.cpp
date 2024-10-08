/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

 // @lc code=start

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int nFast = nums[0];
        int nSlow = nums[0];

        // 第一步：将数组理解为一个链表找到相遇点
        do {
            nSlow = nums[nSlow];
            nFast = nums[nums[nFast]];
        } while (nSlow != nFast);

        // 第二步：找到环的入口
        nSlow = nums[0];
        while (nSlow != nFast) {
            nSlow = nums[nSlow];
            nFast = nums[nFast];
        }

        return nSlow;
    }
};
// @lc code=end

