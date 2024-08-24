/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

 // @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool isValid(const string& str, int start, int end) {
        // 越界处理
        if (start > end) {
            return false;
        }
        // 前导零判定
        if (str[start] == '0' && start != end) {
            return false;
        }

        int num = 0;
        for (int i = start; i <= end; i++) {
            // 判断非法数字
            if (str[i] > '9' || str[i] < '0') {
                return false;
            }
            // 对首位数字的判断逻辑在这里,基本上也算一个ip地址的常识
            num = num * 10 + (str[i] - '0');
            if (num > 255) {
                return  false;
            }
        }

        return true;
    }

    void backtracking(string str, int nStartIndex, int nPointNum) {
        if (nPointNum == 3) {
            if (this->isValid(str, nStartIndex, str.size() - 1)) {
                _vResult.push_back(str);
            }
            return;
        }

        for (int i = nStartIndex; i < str.size(); i++) {
            if (isValid(str, nStartIndex, i)) {
                str.insert(str.begin() + i + 1, '.');
                backtracking(str, i + 2, nPointNum + 1);
                str.erase(str.begin() + i + 1);
            }
            else {
                break;
            }
        }
    }


    vector<string> restoreIpAddresses(string s) {
        /**
         * 有效ip地址规范
         * 不以0,3,4,5,6,7,8,9开头
         * 最多三位数字
         */
        _vResult.clear();
        if (s.size() < 4 || s.size() > 12) {
            return _vResult;
        }
        backtracking(s, 0, 0);
        return _vResult;
    }

private:
    vector<string> _vResult;
};
// @lc code=end

