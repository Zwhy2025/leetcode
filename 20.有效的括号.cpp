/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
    bool isValid(string s)
    {
        if (s.size() % 2 != 0){
            return false;
        }

        std::stack<char> stack;
        for (char ch : s)
        {
            if (ch == '('){         ///<载入前驱括弧
                stack.push(')');
            }
            else if (ch == '{'){    ///< 从上到下的顺序是优先级
                stack.push('}');
            }
            else if (ch == '['){
                stack.push(']');
            }
            else if (stack.empty() ||      ///< 到这里一定是后驱括号匹配
                        stack.top()!=ch ){ ///< 匹配失败,以及没有元素导致匹配失败
                return false;
            }
            else{ ///< 匹配成功 
                stack.pop();
            }
        }
        return stack.empty();
    }
};
// @lc code=end
