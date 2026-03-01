// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
        if (target<0){
           return;
        }
        
        if(target == 0){
            _ret.emplace_back(_path);
            return;
        }
        
        for (int i = startIndex; i < candidates.size(); i++)
        {
            // 很关键的一点是排序之后,前后相同元素是紧挨着的,所以跳过就行
            // i > startIndex  表示同一层 开始遍历
            if (i > startIndex && candidates[i]==candidates[i-1]){
                continue;
            }
        
            _path.emplace_back(candidates[i]);
            // 这里的target使用值传递传参,相当于回溯了
            backtracking(candidates,target-candidates[i],i+1);
            _path.pop_back();
        }
    }

    //1,1,2,5,6,7,10
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        _ret.clear();
        _path.clear();
        sort(candidates.begin(), candidates.end());
        
        backtracking(candidates,target,0);
        return _ret;
    }
};
// @lc code=end

