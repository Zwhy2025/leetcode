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
        //暴力解法
        auto faker = new ListNode();
        faker->next = head;
        auto pos = faker;
        auto trav = faker;

        int len = getListSize(trav);

        //处理异常边界 数组无元素 索引超过限制
        int index = len-n;
        if (len>0 && index < 0){
            return nullptr;
        }

        // 索引到目标点
        while (index--)
        {
            pos=pos->next;
        }
        
        auto tmp=pos->next;
        // 嫁接指针
        pos->next=pos->next->next;
        
        // 清理内存的好习惯
        delete tmp;
        tmp=nullptr;

        return faker->next;
    }

    int getListSize(ListNode *trav)
    {
        int size = 0;
        while (trav->next != nullptr)
        {
            size++;
            trav=trav->next;
        }
        return size;
    }
};
// @lc code=end
