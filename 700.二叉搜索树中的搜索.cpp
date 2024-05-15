/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        queue<TreeNode *> qe;
        if (!root){
            return root;
        }
        qe.push(root);
        while (!qe.empty())
        {
            int size = qe.size();
            for (int i = 0; i < size; i++)
            {
                auto node = qe.front();
                qe.pop();

                //跳过叶子节点
                if (!node){
                    continue;
                }

                // 根据val的大小抉择左子树还是右子树
                if (node->val > val){
                    qe.push(node->left);
                }else if (node->val < val){
                    qe.push(node->right);
                }else{ ///< 此时一定是val==node->val
                    return node;
                }
            }
        }
        return nullptr;
    }
};
// @lc code=end
