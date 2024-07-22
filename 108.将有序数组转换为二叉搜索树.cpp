/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* traverseTree(vector<int>& nums, int start, int end)
    {
        if (start > end) {
            return nullptr;
        }

        // 由于平衡二叉树左右两边的节点数相差不超过1，
        // 所以每次取中间节点作为根节点,则符合此定义
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        // 由于数组有序,递归构造即可
        node->left = traverseTree(nums, start, mid - 1);
        node->right = traverseTree(nums, mid + 1, end);
        return node;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return traverseTree(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test108, Test)
{
    Solution s;
    vector<int> nums = { -10, -3, 0, 5, 9 };
    s.sortedArrayToBST(nums);
}
