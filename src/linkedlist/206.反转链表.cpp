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
 *     ListNode() : val(0), next(nullptr) {
       // TODO
   }
 *     ListNode(int x) : val(x), next(nullptr) {
       // TODO
   }
 *     ListNode(int x, ListNode *next) : val(x), next(next) {
       // TODO
   }
 * };
 */

#ifndef LISTNODE_H
#define LISTNODE_H
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
        // TODO
    }
    ListNode(int x) : val(x), next(nullptr)
    {
        // TODO
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
        // TODO
    }
};
#endif // LISTNODE_H

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // TODO

        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *last = nullptr;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        return last;
    }
};

// @lc code=end
