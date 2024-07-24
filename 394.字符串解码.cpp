/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

 // @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
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
    string decodeString(string s)
    {
        stack<std::pair<std::string, int>> st;
        std::string currString;
        int currNum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {       ///< 考虑高位数字
                currNum = currNum * 10 + (s[i] - '0');
            } else if (s[i] == '[') {  ///< 将历史子串转存,清空状态
                st.push({ currString,currNum });
                currNum = 0;
                currString = "";
            } else if (s[i] == ']') {  ///< 区间内的子串重复并累加
                auto top = st.top();
                st.pop();
                string prevString = top.first;
                int num = top.second;
                for (int i = 0; i < num; i++) {
                    prevString += currString;
                }
                currString = prevString;
            } else {                    ///< 生成区间内子串
                currString += s[i];
            }

        }
        return currString;
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test394, SimpleTest)
{
    Solution s;
    ASSERT_EQ("aaabcbc", s.decodeString("3[a]2[bc]"));
    ASSERT_EQ("accaccacc", s.decodeString("3[a2[c]]"));
    ASSERT_EQ("abcabccdcdcdef", s.decodeString("2[abc]3[cd]ef"));
    ASSERT_EQ("abccdcdcdxyz", s.decodeString("abc3[cd]xyz"));
}
