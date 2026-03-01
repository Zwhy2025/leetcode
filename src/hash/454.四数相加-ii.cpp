/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
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



    int fourSumCount(vector<int>& nums1, 
                     vector<int>& nums2,
                     vector<int>& nums3,
                     vector<int>& nums4) {
        // 思路简单代码实现不了 = 代码能力弱
        // 对数据结构不够熟悉

        // 收集一半
        unordered_map<int,int> umap;
        for(int num1:nums1){
            for(int num2:nums2){
                umap[num1+num2]++;
            }
        }

        // 索引另一半
        int count =0;
        for(int num3:nums3){
            for(int num4:nums4){
                //查找"逆值"
                if(umap.find(0-(num3+num4))!=umap.end()){
                    count+= umap[0-(num3+num4)];
                }
            }
        }
        return count;
    }
};
// @lc code=end

