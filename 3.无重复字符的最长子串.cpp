/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> dict;
        int i = -1 ,res =0, len = s.size();
        for (int j = 0;  j< s.size();  j++)
        {
            if(dict.find(s[j])!=dict.end()){
                i = std::max(i,dict.find(s[j])->second);
            }
            dict[s[j]] = j;
            res = std::max(res,j-i);
        }
        return res;
    }
};
// @lc code=end

