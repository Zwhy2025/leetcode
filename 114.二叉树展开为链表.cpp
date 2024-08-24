/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    vector<TreeNode*> _vNodeList;

    void tickTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        _vNodeList.push_back(node);
        tickTree(node->left);
        tickTree(node->right);
    }


    void flatten(TreeNode* root) {
        _vNodeList.clear();
        tickTree(root);

        if (_vNodeList.empty()) {
            return;
        }

        std::cout << _vNodeList.size() << std::endl;

        for (int i = 0; i < _vNodeList.size() - 1; i++) {
            _vNodeList[i]->right = _vNodeList[i + 1];
            _vNodeList[i]->left = nullptr; // 确保 left 指针为 nullptr
        }
        _vNodeList.back()->right = nullptr;
        _vNodeList.back()->right = nullptr;
    }
};
// @lc code=end

