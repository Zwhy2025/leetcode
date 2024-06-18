/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
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
    vector<vector<int>> _ret;
    vector<int> _path;

    void backtracking(vector<int>& candidates, int target,int startIndex){
        if(target == 0){
            _ret.emplace_back(_path);
            return;
        }else if (target<0){
           return;
        }
        
        for (int i = startIndex; i < candidates.size(); i++)
        {
            _path.emplace_back(candidates[i]);
            // 这里的target使用值传递传参,相当于回溯了
            backtracking(candidates,target-candidates[i],i);
            _path.pop_back();
        }
    }
   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        _ret.clear();
        _path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates,target,0);
        return _ret;
    }
};
// @lc code=end

