/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

 // @lc code=start
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */
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

#ifndef LISTNODE_H
#define LISTNODE_H
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value) :val(value), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#endif // LISTNODE_H

class Solution {
public:
    unordered_map<long long, int> _prefixSumCount;
    int _count;

    void dfs(TreeNode* node, int targetSum, long long currSum)
    {
        if (!node) {
            return;
        }

        currSum += node->val;
        _count += _prefixSumCount[currSum - targetSum];

        _prefixSumCount[currSum]++;
        dfs(node->left, targetSum, currSum);
        dfs(node->right, targetSum, currSum);
        _prefixSumCount[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum)
    {
        _prefixSumCount.clear();
        _prefixSumCount[0] = 1;
        _count = 0;
        dfs(root, targetSum, 0);
        return _count;
    }

};
// @lc code=end

