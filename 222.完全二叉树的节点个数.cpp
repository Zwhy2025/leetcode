/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int travTree(TreeNode *node)
    {
        if (!node)return 0;
        
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        int leftDepth = 0, rightDepth = 0;
        
        while (left){
            left = left->left;
            leftDepth++;
        }
        while (right){
            right = right->right;
            rightDepth++;
        }
        if(leftDepth==rightDepth){
            //计算完全二叉树节点公式
            return (2 <<leftDepth) -1;
        }

        int leftTreeNum = travTree(node->left);         // 左
        int rightTreeNum = travTree(node->right);       // 右
        int result = leftTreeNum + rightTreeNum + 1;    // 中
        return result;    
    }

    int countNodes(TreeNode *root)
    {
        return travTree(root);
    }
};
// @lc code=end
