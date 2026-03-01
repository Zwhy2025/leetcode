/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif // LISTNODE_H

class Solution
{
public:
    int getdepth(TreeNode *node)
    {
        if (node == NULL) return 0;
        int leftdepth = getdepth(node->left);   // 左
        int rightdepth = getdepth(node->right); // 右

        // 怎么处理度不为2的非叶子节点
        if (!node->left && node->right){
            return 1 + rightdepth;
        }

        if (!node->right && node->left){
            return 1 + leftdepth;
        }

        int depth = 1 + std::min(leftdepth, rightdepth); // 中
        return depth;
    }
    int minDepth(TreeNode *root)
    {
        return getdepth(root);
    }
};
// @lc code=end
