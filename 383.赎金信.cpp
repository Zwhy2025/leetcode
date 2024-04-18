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

        if (ransomNote.size() > magazine.size())
        {
            return false;
        }

        // 数值小的时候 数组做哈希表 效率优势大
        int alphabet[26];
        for (auto it :magazine)
        {
            alphabet[it-'a']++;
        }
        
        for (auto it : ransomNote)
        {
           if(!alphabet[it-'a']){
                return false ;
           }else{
               alphabet[it-'a']--;
           }
        }

        return true;
    }
};
// @lc code=end
