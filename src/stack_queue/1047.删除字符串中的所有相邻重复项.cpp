/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
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
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto &&ch : s)
        {
            if(!res.empty()&&res.back()==ch){
                res.pop_back();
            }else{
                res.push_back(ch);
            }
        }
        return res;
    }
};
// @lc code=end

