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

    std::string repeatString(const std::string& str, int times) {
        std::string result;
        for (int i = 0; i < times; ++i) {
            result += str;
        }
        return result;
    }

    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size() / 2; i++) {
            
            string str = s.substr(0, i);
            if (s == repeatString(str, s.size() / i)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

