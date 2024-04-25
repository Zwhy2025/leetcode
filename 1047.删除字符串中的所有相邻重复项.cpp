/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
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
    string removeDuplicates(string s) {
        stack<char> stack;
        for(auto ch : s){
            // 这里很关键的一点是 消消乐第二轮
            // 其实 会继续判断
            // 刚开始脑子卡了 外面加了一个循环
            if (!stack.empty()&&stack.top()==ch)
            {
                stack.pop();
            }else{
                stack.push(ch);
            }
        }
        s.clear();
        while (!stack.empty())
        {
            s.push_back(stack.top());
            stack.pop();
        }

        // 经过一轮入栈之后,顺序其实逆序了
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end

