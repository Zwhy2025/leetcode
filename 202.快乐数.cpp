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
         * 1. 符合快乐数:"1,10,100,1000,...."
         * 2. 不符合循环终止条件:
         */
        auto set = unordered_set<int>();

        while (true)
        {
            int sum = calculate(n);
            if (sum == 1)
            {
                return true;
            }

            if (set.count(sum))
            {
                return false;
            }
            else
            {
                set.insert(sum);
            }

            n = sum;
        }
    }
}
;
// @lc code=end
