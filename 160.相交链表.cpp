// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem160.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        auto faker_A = new ListNode();
        faker_A->next=headA;
        auto pos_A = faker_A;
        while (pos_A->next!=nullptr)
        {   
            auto faker_B = new ListNode();
            faker_B->next=headB;
            auto pos_B =faker_B;
            while (pos_B->next!=nullptr)
            {
                if (pos_A->next == pos_B->next)
                {
                   return pos_A->next;
                }
                pos_B=pos_B->next;
            }
            pos_A=pos_A->next;
            
        }

        return nullptr; 
    }
};
// @lc code=end

