// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
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
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            //同样是两次遍历,为啥这里面就是o(1)
            // 这是因为 unordered_map底层是哈希表
            // 而且 unordered_map 也不用排序
            // 所以这里属于以空间换时间(两次遍历无额外申请空间)
            auto it = map.find(target - nums[i]);
            if (it != map.end())
            {
                return {it->second, i};
            }
            map[nums[i]] = i;
        }
        return {0, 0};
    }
};
// @lc code=end
