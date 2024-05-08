/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root){
        queue<TreeNode *> qe;
        if (!root){
            return 0;
        }
        qe.push(root);
        int ret = 0;

        while (!qe.empty())
        {
            // 每次遍历一层
            int size = qe.size();
            for (int i = 0; i < size; i++)
            {
                
                auto node = qe.front();
                qe.pop();
                
                //取每层第一个节点的val
                if(i==0){
                    ret = node->val;
                }
   
                if (node->left){
                    qe.push(node->left);
                }

                if (node->right){
                    qe.push(node->right);
                }
            }
 
        }
        return ret;

    }
};
// @lc code=end

