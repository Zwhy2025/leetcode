/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifndef LISTNODE_H
#define LISTNODE_H
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int value):val(value),left(nullptr),right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif // LISTNODE_H

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 遇到子节点 或者空结点直接返回 后续都不需要遍历了
        if(!root || root == p || root ==q){
            return root;
        }
        // 后序遍历哪怕遇到当前节点也会继续往下走
        auto left = lowestCommonAncestor(root->left,p,q);
        auto right = lowestCommonAncestor(root->right,p,q);

        if(left&&right){
            return root;
        }
        
        // 只要遇到有子树含有索引节点 直接
        return left ? left : right;
    }
};
// @lc code=end

