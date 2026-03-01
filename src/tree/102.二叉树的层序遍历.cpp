/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        std::queue<TreeNode *> dq;
        if(root){
            dq.push(root);
        }
            
        while (!dq.empty())
        {
            int size = dq.size();
            vector<int> tmp;
            // 层序遍历一次要遍历两个节点
            // 但是遍历根节点和最后一个非双节点的时候
            // 需要动态调整到一个
            for (int i = 0; i < size; i++)
            {
                auto node = dq.front();
                dq.pop();
                tmp.push_back(node->val);

                if (node->left){
                    dq.push(node->left);
                }

                if (node->right){
                    dq.push(node->right);
                }
              
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end
