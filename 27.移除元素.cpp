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
        // 如果找到一个,逻辑上少遍历一个元素,
        // 因为最后末尾元素逻辑上删除,size--
        int size = nums.size();
        for (int i = 0; i < size;)
        {
            if (nums[i] == val)
            {
                size--;
                for (int j = i + 1; j < nums.size(); j++){///< 使用后续元素覆盖
                   
                    nums[j - 1] = nums[j];
                }
            }
            else ///< 处理遍历的逻辑在这,因为如果找到抹除一个元素,当前元移动,会自动遍历
            {
                i++;
            }
        }

        return size;
    }
};
// @lc code=end
