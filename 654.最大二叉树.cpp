/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int value):val(value),left(nullptr),right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif // LISTNODE_H

class Solution {
public:


    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if(nums.empty()){
            return nullptr;
        }  
        //{3,2,1,6,0,5}
        
        auto it = std::max_element(nums.begin(),nums.end());
    
        TreeNode* node = new TreeNode(*it);
    
        vector<int> leftNode(nums.begin(),it);
        vector<int> rightNode(it+1,nums.end());
        
        node->left =constructMaximumBinaryTree(leftNode);
        node->right =constructMaximumBinaryTree(rightNode);
        return node;
    }
};
// @lc code=end

