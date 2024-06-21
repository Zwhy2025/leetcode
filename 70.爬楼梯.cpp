/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
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
    int _res =0;
    void backtracking(int n,int sum){
        if (n == sum){
            _res++;
            return;
        }

        for (int i = 1; i < 3 && sum<=n ; i++)
        {
            backtracking(n,sum+i);
        }
    }

    int climbStairs(int n) {
        _res =0;
        backtracking(n,0);
        return _res; 
    }
};
// @lc code=end

