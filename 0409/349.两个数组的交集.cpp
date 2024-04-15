/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        //使用 vector初始化set 是内置方法
        unordered_set<int> set2(nums2.begin(), nums2.end());

        unordered_set<int> ret;

        // 遍历 set1 并检查 set2 中是否存在相同的元素
        // 逻辑上,只需要遍历任何一个就行了,因为是求交集,这点愚蠢了
        for (auto it = nums1.begin(); it != nums1.end(); ++it)
        {
            if (set2.find(*it) != set2.end())
            {
                ret.insert(*it);
            }
        }
        // 开销上差不多,因为实际上用的是相同的方法,只是有更加优雅的方式
        return vector<int>(ret.begin(),ret.end());
    }
};
// @lc code=end
