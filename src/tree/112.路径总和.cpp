/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int travTree(TreeNode *node, int count)
    {
        /** 判断是否到达叶子节点,注意这样的判断会忽略空结点 */
        if (!node->left && !node->right){
            if (count == 0){ ///< 此时如果count递减到0说明路径符合target,终止递归
                return true;
            }
            else{
                return false;
            }
        }

        if (node->left){
            count -= node->left->val;
            if (travTree(node->left, count)){ ///< 判断是否符合条件
                return true;
            }
            count += node->left->val; ///< 回溯遍历过的节点
        }

        if (node->right){
            count -= node->right->val;
            if (travTree(node->right, count)){
                return true;
            }
            count += node->right->val;
        }

        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr) {
            return false;
        }
        return travTree(root, targetSum - root->val);
    }
};
// @lc code=end
