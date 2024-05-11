/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
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
    // ascii + 数组大小
    #define ARRAY_SIZE 129
    int lengthOfLongestSubstring(string s) {
        int max =0;
        for (int i = 0; i < s.size(); i++)
        {
            int cmap[ARRAY_SIZE]={};
            for (int j = i; j < s.size(); j++)
            {
                //如果有重复的直接恢复出厂设置,到下一个点开始遍历
                if( cmap[s[j]]){
                    // 将所有元素设置为 0
                    memset(cmap, 0, sizeof(cmap)); 
                    break;
                }else{
                    // 更新哈希值 不重复的元素 最大字串
                    cmap[s[j]]++;
                    cmap[ARRAY_SIZE-1]++;
                    max = std::max(cmap[ARRAY_SIZE-1],max);
                }
            }
        }
        return max;
    }
};
// @lc code=end

