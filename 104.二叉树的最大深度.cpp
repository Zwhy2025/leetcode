/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

    int maxDepth(TreeNode *root)
    {
        std::queue<TreeNode*> qe;
        int ret = 0;
        if(!root) return ret;
        qe.push(root);
        while(!qe.empty())
        {   //每次遍历一层
            int size = qe.size();
            // 每次到达一层深度自增
            ret++;
            // 完成每一层所有节点的迭代
            for (int i = 0; i < size; i++)
            {
                auto node = qe.front();
                qe.pop();
                if (node->left) qe.push(node->left);
                if (node->right) qe.push(node->right);
            }
        
        }
        return ret;
    }
};
// @lc code=end
