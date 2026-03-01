// @before-stub-for-debug-begin
#include <vector>
#include <string>


using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
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
using namespace std;
class Solution
{
public:
   vector<int> CreateVector(string str)
    {
        vector<int> vect;
        vect.resize(26,0);
        for (auto s : str)
        {
            vect[int(s)-97]++;
        }
        return vect;
    }

    bool isAnagram(string s, string t)
    {
        
        return CreateVector(s) == CreateVector(t);
    }
};
// @lc code=end
