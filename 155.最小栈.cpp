/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
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

class MinStack {

private:
    stack<int> _minStack;  ///< 从上到下存储递减的元素
    stack<int> _mainStack; ///< 先进后出
public:
    MinStack() {}
    
    void push(int val) {
        _mainStack.push(val);
        // 第一次进来默认最小,后续就只记录比top更小的值,保证了单调性
        if(_minStack.empty() || val <= _minStack.top()){
            _minStack.push(val);
        }
    }
    
    void pop() {
        // 出栈的时候需要检查是不是,pop到最小栈中的元素,否者不需要处理
        if (_mainStack.top() == _minStack.top()){
            _minStack.pop();
        }
        _mainStack.pop();
    }
    
    int top() {
        return _mainStack.top();
    }
    
    int getMin() {
        return _minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

