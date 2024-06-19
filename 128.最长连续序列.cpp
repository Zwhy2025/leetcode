/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
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

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 以空间换时间
        // 在循环外的构造,时间复杂度 (O)n
        // 换取后续循环中的常量查找耗时
        unordered_set<int> num_set(nums.begin(),nums.end());
        int max_len = 0;
        for (auto &&num : nums)
        {
            // 找到连续序列的起点
            // 连续序列存在,对于n必须存在错位数字n-1
            if(num_set.find(num -1) == num_set.end()){
                int cur_num = num;
                int cur_len =  1;

                // 索引到连续序列末尾
                while (num_set.find(cur_num+1)!=num_set.end())
                {
                    cur_len++;
                    cur_num++;
                }
                //  存储整个遍历期间的最大长度
                max_len = max(cur_len,max_len);
            }
        }
        // 时间复杂度的计算while并不是会处理每一个元素
        // 所以最坏情况时间复杂度是O(2n) 也就O(n)
        return max_len;
    }
};
// @lc code=end

