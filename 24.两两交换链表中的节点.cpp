/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        auto it = dummy;

        while (it->next && it->next->next) {    
            auto back = it->next;
            auto front = it->next->next;

            // 请记住 先实现 后优化
            // 不然怎么称之为优化?
            it->next = front;
            back->next = front->next;
            front->next =back;

            it = it->next->next;
        }

        return dummy->next;
    }
};
// @lc code=end

