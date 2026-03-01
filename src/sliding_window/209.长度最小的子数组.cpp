/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
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
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int res = INT32_MAX;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                subLength = (j - i + 1);
                res = res < subLength ? res : subLength;
                sum -= nums[i++];
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};
// @lc code=end

