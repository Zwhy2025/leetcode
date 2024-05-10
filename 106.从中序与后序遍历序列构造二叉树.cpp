/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
        {
            return nullptr;
        }

        // 后序遍历数组中最后一个元素一定是根节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);

        if (postorder.size() == 1){
            return root;
        }

        // 查找中序遍历中根节点的位置,此时一定是左子树,根节点,右边子树
        int index;
        for (index = 0; index < inorder.size(); index++){
            if (inorder[index] == rootValue){
                break;
            }
        }

        // 生成后续迭代中序数组
        // 根据中序节点位置 去把下一次迭代的左右子树的中序遍历结构切割出来
        // 记住此时一定是左开右边闭
        vector<int> leftInordr(inorder.begin(), inorder.begin() + index);
        vector<int> rightInordr(inorder.begin() + index + 1, inorder.end());

        // 生成后续迭代后序数组
        // 不管怎样左右子树的数量一定是相等的,可以用这一点来辅助切割
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostordr(postorder.begin(),
                                 postorder.begin() + leftInordr.size());
        vector<int> rightPostordr(postorder.begin() + leftInordr.size(),
                                  postorder.end());

        // 遍历左右子树
        root->left = traversal(leftInordr, leftPostordr);
        root->right = traversal(rightInordr, rightPostordr);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0){
            return nullptr;
        }
        return traversal(inorder, postorder);
    }
};
// @lc code=end
