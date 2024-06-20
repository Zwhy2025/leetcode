/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
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
    vector<string> _ret;
    void backtracking(string s, int startIndex, int pointNum)
    {   
        // 结尾判定 . 的数量
        if (pointNum == 3){   
            //验证最后一段是符合规范,不符合不加入返回容器
            if (isValid(s, startIndex, s.size() - 1)){
                _ret.push_back(s);
            }
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            // 每个层序遍历的子串,进行校验
            if (isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                // 不用路径记录path,原字符串上增加逗号,回溯后按添加顺序擦除
                // pointNum以零时遍历形式传入,函数调用返回后自动回溯
                backtracking(s, i + 2, pointNum + 1);
                s.erase(s.begin() + i + 1);
            }
            else{
                break;
            }
        }
    }

    bool isValid(const string &s, int start, int end)
    {
        /**
         *  有效ip地址规范
         *  字符串不包含前导0
         *  不以3,4,5,6,7,8,9开头
         *  最多三位数
         *
         *
         *  1.只包含数字
         *  2.不包含前导0,但是单个0可以
         *  3.数字的值不大于255
         */

        if (start > end){
            return false;
        }

        if (s[start] == '0' && start != end){
            return false;
        }

        int num = 0;
        for (int i = start; i <= end; i++)
        {
            if (s[i] > '9' || s[i] < '0'){
                return false;
            }

            num = num * 10 + (s[i] - '0');
            if (num > 255){
                return false;
            }
        }

        return true;
    }

    vector<string> restoreIpAddresses(string s)
    {

        _ret.clear();
        if (s.size() < 4 || s.size() > 12){
            return _ret;
        }
        backtracking(s, 0, 0);
        return _ret;
    }
};
// @lc code=end
