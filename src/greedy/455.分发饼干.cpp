/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int index = s.size() -1;
        int res = 0;
        // 大饼干优先喂饱大胃口
        for (int i = g.size()-1; i >=0; i--)
        {
            if (index>=0&& s[index]>=g[i])
            {
                res++;
                index++;
            }
        }
        return res;   
    }
};
// @lc code=end

