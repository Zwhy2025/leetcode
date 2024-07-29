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
    int cal(int op1, int op2, string symbol)
    {
        // 理论情况不会出现else,其实还是要考虑的
        if (symbol == "*") {
            return  op2 * op1;
        } else  if (symbol == "/") {
            return  op2 / op1;
        } else  if (symbol == "+") {
            return  op2 + op1;
        } else   if (symbol == "-") {
            return   op2 - op1;
        } else {
            return INT_MAX;
        }
    }

    int evalRPN(vector<string>& tokens)
    {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            // 遇到运算符，取出栈顶两个元素进行运算,并将结果压入栈中
            if (tokens[i] == "*" || tokens[i] == "/" ||
                tokens[i] == "+" || tokens[i] == "-") {

                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();

                nums.push(this->cal(op1, op2, tokens[i]));
            } else {
                nums.push(std::stoi(tokens[i]));

            }
        }
        // 栈顶元素即为最终结果
        return nums.top();
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test150, Test)
{
    Solution s;
    std::vector<std::string> vec = { "2", "1", "+", "3", "*" };
    //ASSERT_EQ(s.evalRPN(vec), 9);

    vec = { "4", "13", "5", "/", "+" };
    ASSERT_EQ(s.evalRPN(vec), 6);

    vec = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };

}