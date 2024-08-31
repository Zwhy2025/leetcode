/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
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

    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size() / 2; i++) {

            if (s.size() % i == 0) {
                bool match = true;
                for (int j = i; j < s.size(); j++) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) return true;
            }
        }
        return false;

    }
};
// @lc code=end

