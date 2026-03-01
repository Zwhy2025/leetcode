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


    void push(int x)
    {
        _input.push(x);
    }

    int pop()
    {
        if (_output.empty())
        {
            while(!_input.empty()){
                _output.push(_input.top());
                _input.pop();
            }
        }
        int ret = _output.top();
        _output.pop();
        return ret;
    }

    int peek()
    {
        int ret = this->pop();
        _output.push(ret);
        return ret;
    }

    bool empty()
    {
        return _input.empty() && _output.empty();
    }

    std::stack<int> _input;
    std::stack<int> _output;
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
