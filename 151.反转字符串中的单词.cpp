/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
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
    string reverseWords(string s)
    {
        std::stack<std::string> strStack;

        std::string tmp = "";
        for (char c : s)
        {
            if (c != ' '){
                tmp.push_back(c);
            }
            else{
                if (!tmp.empty())
                {
                    strStack.push(tmp);
                    tmp.clear();
                }
            }
        }

        if (!tmp.empty())
        {
            strStack.push(tmp);
            tmp.clear();
        }

        while(!strStack.empty()){
            tmp.append(strStack.top());
            tmp.push_back(' ');
            strStack.pop();
        }
        tmp.erase(tmp.end()-1);
        return tmp;

    }
};
// @lc code=end
