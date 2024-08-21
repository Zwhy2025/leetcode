/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
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
    void reverseString(vector<char>& s) {

        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
    }
   
};
 // @lc code=end