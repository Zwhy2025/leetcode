/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
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
    int calculate(int num)
    {

        int ret = 0;
        while (num)
        {
            ret += (num % 10) * (num % 10);
            num /= 10;
        }
        return ret;
    }

    bool isHappy(int n)
    {
        /**
         * 快慢指针解决循环问题
         * 前提条件一定要推导出非快乐数字一定会回归到一个循环
         * 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
         * 而快乐数字也会回归到循环
         * 1->1->1->....
         */

        int back = n;
        int front = n;
        do
        {
            back = calculate(back);
            front = calculate(calculate(front));
        } while (back != front);

        return front == 1;
    }
};
// @lc code=end
