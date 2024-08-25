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
        unordered_map<int, bool> mapCaches;
        for (auto&& num : nums) {
            if (mapCaches[num]) {
                return  num;
            }
            mapCaches[num] =true;
        }
        return INT_MAX;
    }
};
// @lc code=end

