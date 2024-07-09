/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
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
    string decodeString(string s) {
        std::stack<std::pair<std::string, int>> stack;
        std::string strCurrString;
        int nCurrNum = 0;

        for (auto &&ch : s)
        {
            if(std::isdigit(ch)){
                nCurrNum =nCurrNum * 10+(ch - '0');
            }else if (ch =='['){
                stack.push({strCurrString,nCurrNum});
                nCurrNum = 0;
                strCurrString ="";
            }else if(ch ==']'){
                std::pair<std::string,int> top = stack.top();
                stack.pop();
                std::string strPrevString = top.first;
                int num = top.second;
                for (int i = 0; i < num; i++)
                {
                    strPrevString += strCurrString;
                }
                strCurrString = strPrevString;
            }else{
                strCurrString += ch;
            }
        }
        return strCurrString;
    }
};
// @lc code=end

