/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

 // @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
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
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        // 构造杂志字典
        int alphabet[26];
        for (auto it : magazine) {
            alphabet[it - 'a']++;
        }

        // 遍历赎金信, 检查是否可以构造,如果缺少字母,则立即返回false
        for (auto it : ransomNote) {
            if (!alphabet[it - 'a']) {
                return false;
            } else {
                alphabet[it - 'a']--;
            }
        }

        return true;
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test383, SimpleTest)
{
    Solution s;
    EXPECT_EQ(s.canConstruct("cibdccdjhgihcdchibjfhhcafebfcdbjhfiebceeihfifbbecajfidfcfceghaddcjgcaajahbdcddebgafieehchgcigdggibjcajabbaghffgijjejcafajafagegfgihahjgajhhdfehgfgagedjbdcgdciiijciiceahbgbdfcifdadhgieiaadcjgifaaefcacgiaifiahidhchficddgaaaigdbbafabeciedcihbfefidfihcehfeihacbbjiffadbiiacjdidbfahehiicchecgjbbfdeaieafbdbhfigbihjiehjhjicbeaicbeeeefcgbihjajahjhfbddecijhhafdgbfbhicfdijecgchbcdccgajjbadfddjdbdaebehejdhjabecjgffafjbdcidhafchheefhjfciafiaffgbifgddeajfdeacgjfaaeahgaacefafcdadhaabajbdieahajfficfedhieaahdbhhbfgcicbbifbieeiheihgbebggfidfiggeaejgfgbbdjgchihibjghfceabcdjafabhceghegadgfcgeieigdjacbcecfgfhebidfajeifbgejfhhbajhidadgjfbcfgfdehcfgdbhhafgfbghfebfeccddbgebaeeghaccjiiiicgiibjfeacdbdfbahfefabgbaibbfgjcaccjjcggdidhajffacgdghcia", "b"), false);
    EXPECT_EQ(s.canConstruct("aa", "ab"), false);
    EXPECT_EQ(s.canConstruct("aa", "aab"), true);
}
