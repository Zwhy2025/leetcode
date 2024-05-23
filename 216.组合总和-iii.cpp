/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
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
    vector<vector<int>> ret;
    vector<int> path;
    void backtracking(int k, int n,int sum,int index){

         //  确定回溯算法边界是遍历深度由题限制
        if (path.size() == k)
        {
            // 符合要求的组合限制条件
            if(sum ==k){
                ret.push_back(path);
            }
            return;
        }

        // 回溯算法的递归遍历思想
        for (size_t i = index; i <= 9; i++)
        {
            // 自增后减少,回溯算法核心
            sum+=i;
            path.push_back(i);
            this->backtracking(k,n,sum,i+1);
            path.pop_back();
            sum-=i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ret.clear();
        path.clear();
        backtracking(k,n,0,1);
        return ret;
    }
};
// @lc code=end

