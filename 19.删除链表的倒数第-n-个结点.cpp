/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 快慢指针
        auto faker = new ListNode();
        faker->next = head;

        auto back = faker;
        auto front = faker;

        while (front->next != nullptr)
        {
            if (n > 0)///< 快指针先走
            {
                n--;
                front = front->next;
            }
            else ///< 同时移动
            {
                front = front->next;
                back = back->next;
            }
        }

        // 删除节点
        auto tmp = back->next;
        back->next=back->next->next;

        // 清理内存
        delete tmp;
        tmp=nullptr;

        return faker->next;
    }
};
// @lc code=end
