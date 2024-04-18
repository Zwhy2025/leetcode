/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
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
    bool canConstruct(string ransomNote, string magazine)
    {
        auto sMagazine = unordered_multiset<char>(magazine.begin(), magazine.end());
        
        for (auto c : ransomNote)
        {
            if(!sMagazine.count(c)){
                return false;
            }else{
                auto it = sMagazine.find(c);
                sMagazine.erase(it);
            }
        }

        return true;
    }
};
// @lc code=end
