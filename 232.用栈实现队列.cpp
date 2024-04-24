/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
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

class MyQueue
{
public:
    MyQueue()
    {
    }

    /**
     * @brief 交换两个栈中数据
     * @param output 输出
     * @param input 输入
     */
    void exchange(stack<int> &output, stack<int> &input)
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
    }

    void push(int x)
    {
        exchange(_last, _front);
        _last.push(x);
    }

    int pop()
    {
        if (!_last.empty())
        {
            exchange(_front, _last);
        }
        int ret = _front.top();
        _front.pop();
        return ret;
    }

    int peek()
    {
        if (!_last.empty())
        {
            exchange(_front, _last);
        }
        int ret = _front.top();
        return ret;
    }

    bool empty()
    {
        return !_front.size() && !_last.size();
    }

    std::stack<int> _last;
    std::stack<int> _front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
