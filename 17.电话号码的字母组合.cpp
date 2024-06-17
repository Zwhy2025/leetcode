/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
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
private:
    // 枚举
    const string _letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
    vector<string> _result;
    string _path;

public:
    void backtracking(const string &disits, int index)
    {
        if (index == disits.size()){
            _result.push_back(_path);
            return;
        }
        
        int digit = disits[index] - '0';    // char转int
        string letters = _letterMap[digit]; // 映射字符集
        for (int i = 0; i < letters.size(); i++)
        {
            _path.push_back(letters[i]);
            backtracking(disits, index + 1); // 递归
            _path.pop_back();                // 回溯
        }
    }

    vector<string> letterCombinations(string digits)
    {
        _path.clear();
        _result.clear();
        if (digits.empty()){
            return _result;
        }

        this->backtracking(digits, 0);
        return _result;
    }
};
// @lc code=end
