/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

 // @lc code=start
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */

#ifndef LISTNODE_H
#define LISTNODE_H
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif // LISTNODE_H

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* left = nullptr;
        ListNode* right = head;
        ListNode* tmp = nullptr;
        
        // 有的时候是不需要头节点,做起来反而麻烦
        while (right) {
            tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }

        return left;
    }
};
// @lc code=end

