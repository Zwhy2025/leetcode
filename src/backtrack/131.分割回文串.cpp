/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
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
public:
    vector<vector<string>> _ret;
    vector<string> _path;
    
    /** 回文串判定 */
    bool _isJustice(string& str,int start,int end){
        // 从原字符串判定性能更好,且更加简单
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (str[i]!=str[j]){
               return false;
            }
        }
        return true;
    }


    void _backtracking(string str,int startIndex)
    {
        // 单次分割结束,不论是第几轮分割结束的边界都是
        // startIndex 递增到结尾
        if(startIndex>=str.size()){
            _ret.push_back(_path);
            return;
        }
        
        // 递归问题其实分解为了
        // 1. 从0开始遍历,一次选取一个
        // 2. 从1开始遍历,一次选取两个
        // 3. ... 
        for (int i = startIndex; i < str.size(); i++){
            if(this->_isJustice(str,startIndex,i)){
                // 分割子串本质上还是顺序遍历,
                // 因为是顺序切割
                auto s = str.substr(startIndex,i-startIndex+1);
                _path.push_back(s);
            }else{
                continue;
            }
            
            _backtracking(str,i+1);
            _path.pop_back();
        }
        
    }

    vector<vector<string>> partition(string s){
        _ret.clear();
        _path.clear();

        _backtracking(s,0);
        return _ret;
    }
};
// @lc code=end
