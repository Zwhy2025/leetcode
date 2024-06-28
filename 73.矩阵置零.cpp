/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
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
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_set<int> set_i;
        unordered_set<int> set_j;

        for (int i = 0; i < matrix.size(); i++)
        {
           for (int j = 0; j < matrix[i].size(); j++)
           {
                if(matrix[i][j]==0){
                    set_i.insert(i);
                    set_j.insert(j);
                }
           }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
           for (int j = 0; j < matrix[i].size(); j++)
           {
                if(set_i.count(i)||(set_j.count(j))){
                    matrix[i][j]=0;
                }
           }
        }
    }
};
// @lc code=end

