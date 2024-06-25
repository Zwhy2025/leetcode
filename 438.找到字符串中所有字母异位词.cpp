/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen){
            return res;
        }
        //数组做哈希
        vector<int> sCount(26, 0), pCount(26, 0);
        for (auto &&c : p){
            pCount[c - 'a']++;
        }

        for (int i = 0; i < sLen; i++)
        {
            sCount[s[i] - 'a']++;
            if (i >= pLen){
                // 滑动窗口
                sCount[s[i - pLen] - 'a']--;
            }

            if (sCount == pCount){
                res.push_back(i - pLen + 1);
            }
        }
        return res;
    }
};
// @lc code=end
