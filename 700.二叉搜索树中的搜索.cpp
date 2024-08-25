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
#include <algorithm>
using namespace std;
#endif // LISTNODE_H
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == nullptr) {
            return nullptr;
        }
        queue<TreeNode*> qe;
        qe.push(root);

        while (!qe.empty()) {
            int size = qe.size();

            for (int i = 0; i < size; i++) {
                auto node = qe.front();
                qe.pop();

                if (node == nullptr) {
                    continue;
                }
                else if (node->val < val) {
                    qe.push(node->right);
                }
                else if (node->val > val) {
                    qe.push(node->left);
                }
                else {
                    return node;
                }
            }
        }
        return nullptr;
    }
};
// @lc code=end

