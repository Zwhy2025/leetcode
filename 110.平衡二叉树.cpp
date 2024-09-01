/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <climits>
#include <algorithm>
using namespace std;

#ifndef LISTNODE_H
#define LISTNODE_H
struct TreeNode {
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

    int tickTree(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int nLeft = tickTree(node->left);
        int nRight = tickTree(node->right);

        /**
         * 1.存在不平衡的情况直接结束递归层层上报
         * 2.递归计算左右子树的高度
         */
        if (nLeft == INT32_MIN || nRight == INT32_MIN) {
            return INT32_MIN;
        }
        else if (std::abs(nLeft - nRight) >= 2) {
            return INT32_MIN;
        }
        else {
            return std::max(nLeft, nRight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return tickTree(root) != INT32_MIN;
    }
};
// @lc code=end


#include<gtest/gtest.h>
TEST(LeetCode110, test1) {
    Solution s;
    auto tree = TreeNode(3);
    tree.left = new TreeNode(9);
    tree.right = new TreeNode(20);
    tree.right->left = new TreeNode(15);
    tree.right->right = new TreeNode(7);

    EXPECT_EQ(s.isBalanced(&tree), true);
}
