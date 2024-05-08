/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (!root){
            return 0;
        }
        st.push(root);
        int ret = 0;
        while (!st.empty())
        {
            auto node = st.top();
            st.pop();
            
            // 判断左叶子节点的条件
            if (node->left &&
                !node->left->left &&
                !node->left->right)
            {
                ret += node->left->val;
            }

            if (node->right){
                st.push(node->right);
            }
            if (node->left){
                st.push(node->left);
            }

            continue;
        }
        return ret;
    }
};
// @lc code=end
