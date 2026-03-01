/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
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
    class MonoDeque
    {
    public:
        void pop(int value)
        {
            // 队列中不一定存了 滑动窗口的元素
            if (!_deque.empty() && value == _deque.front()) {
                _deque.pop_front();
            }
        }

        void push(int value)
        {
            // 大脑混乱&
            while (!_deque.empty() && value > _deque.back()){
                _deque.pop_back();
            }
            _deque.push_back(value);
        }

        int max(){
            return _deque.front();
        }

    private:
        std::deque<int> _deque;
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MonoDeque que;
        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }

        res.push_back(que.max());
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.max());
        }
        return res;
    }
};
// @lc code=end
