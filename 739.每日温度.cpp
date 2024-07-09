/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures(vector<int>& T)
    {
        vector<int> res(T.size(), 0);
        stack<int> st;
        for (int i = 0; i < T.size(); i++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                auto item = st.top();
                st.pop();
                res[item] = i - item;
            }
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

