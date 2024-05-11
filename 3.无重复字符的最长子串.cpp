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
    int lengthOfLongestSubstring(string s) {
        std::size_t max =0;
        for (int i = 0; i < s.size(); i++)
        {
            set<char> set;
            for (int j = i; j < s.size(); j++)
            {
                if(set.count(s[j])){
                    set.clear();
                    break;
                }else{
                    set.insert(s[j]);
                    max = std::max(set.size(),max);
                }
            }

        }
        return max;
    }
};
// @lc code=end

