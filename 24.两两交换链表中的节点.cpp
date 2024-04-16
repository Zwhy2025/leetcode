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
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif // LISTNODE_H

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        auto faker = new ListNode();
        faker->next = head;
        auto pos = faker;

        while (pos->next != nullptr && pos->next->next!=nullptr)
        {
            //缓存
            ListNode* back=pos->next;
            ListNode* front=pos->next->next;

            // 交换
            pos->next=front;
            back->next =front->next;
            front->next=back;
           
            //前进
            pos=pos->next->next;
        }
        //返回
        return faker->next;
    }
};
// @lc code=end
