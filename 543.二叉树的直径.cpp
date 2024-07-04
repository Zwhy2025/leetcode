/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int _nMaxDepth = 0;

    int tickTree(TreeNode* node)
    {
        if (!node) {
            return 0;
        }
        // 后序遍历求左右子树的深度
        int left = tickTree(node->left);
        int right = tickTree(node->right);
        
        // 记录全局最大深度
        _nMaxDepth = std::max(_nMaxDepth, left + right);
        
        // 递归子树的深度计算公式
        return std::max(left,right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        tickTree(root);
        return _nMaxDepth;
    }
};
// @lc code=end

