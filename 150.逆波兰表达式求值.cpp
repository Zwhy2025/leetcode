/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
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
    int evalRPN(vector<string>& tokens) {
        stack<string> stack;
        for(auto str : tokens){
            if (str=="+")
            {
                int a = std::stoi(stack.top());
                stack.pop();
                int b = std::stoi(stack.top());
                stack.pop();
                stack.push(std::to_string(b+a));
            }else if(str=="-") {
                int a = std::stoi(stack.top());
                stack.pop();
                int b = std::stoi(stack.top());
                stack.pop();
                stack.push(std::to_string(b-a));
            }else if(str=="/"){
                int a = std::stoi(stack.top());
                stack.pop();
                int b = std::stoi(stack.top());
                stack.pop();
                stack.push(std::to_string(b/a));
            }else if(str=="*"){
                int a = std::stoi(stack.top());
                stack.pop();
                int b = std::stoi(stack.top());
                stack.pop();
                stack.push(std::to_string(b*a));
            }else{
                stack.push(str);
            }
        }
        return std::stoi(stack.top());
    }
};
// @lc code=end

