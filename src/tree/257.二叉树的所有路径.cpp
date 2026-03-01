/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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

using namespace std;

class Solution {
public:
    void travTree(TreeNode* node , vector<int>& path,vector<string>& ret){
        path.push_back(node->val);

        // 终止条件 遍历到叶子节点
        if(!node->left&&!node->right){
            string sPath;
            // 这样遍历的原因是想要组成题目要求的格式
            for (int i = 0; i < path.size()-1; i++)
            {
                sPath+=std::to_string(path[i]);
                sPath+="->";
            }
            sPath+= std::to_string(path[path.size()-1]);
            ret.push_back(sPath);          
            return;
        }

        if(node->left){
            travTree(node->left,path,ret);
            path.pop_back();
        }

        if(node->right){
            travTree(node->right,path,ret);
            path.pop_back();
        }

    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        vector<int> path;
        if(root == nullptr) return ret;
        travTree(root,path,ret);
        return ret;
    }
};
// @lc code=end

