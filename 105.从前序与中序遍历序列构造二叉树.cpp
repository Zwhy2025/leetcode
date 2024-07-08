/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* tickTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd,
        int intStart, int inEnd, unordered_map<int, int>& inMap)
    {
        // 最难的是这里的循环结束的边界条件
        if (preStart > preEnd || intStart > inEnd) {
            return nullptr;
        }

        int nodeVal = preorder[preStart];
        auto node = new TreeNode(nodeVal);
        int nodeIndex = inMap[nodeVal];
        // 根据查到的索引和起始中序序号可以得到左子树的节点数,右边子树的节点树也就顺势的得到了
        int numsLeft = nodeIndex - intStart;

        // 这里的边界条件值得考虑
        node->left = tickTree(preorder, inorder, preStart + 1, preStart + numsLeft, intStart, nodeIndex - 1, inMap);
        node->right = tickTree(preorder, inorder, preStart + numsLeft + 1, preEnd, nodeIndex + 1, inEnd, inMap);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        unordered_map<int, int> inMap;
        // 构造map 减少从中序遍历找到先序遍历父节点的时间
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return tickTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap);
    }
};
// @lc code=end

