/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        for (auto &&str : strs) {
            // 将字符串排序
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            
            // 将排序后的字符串作为键
            map[sortedStr].push_back(str);
        }
        
        // 收集结果
        vector<vector<string>> ret;
        for (auto &&m : map) {
            ret.push_back(m.second);
        }

        return ret;
    }
};
// @lc code=end

