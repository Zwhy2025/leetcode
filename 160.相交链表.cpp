// @before-stub-for-debug-begin
#include <vector>
#include <string>

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
        faker_A->next = headA;
        auto setNodes = unordered_set<ListNode*>();
        while (faker_A->next!= nullptr)
        {
            setNodes.emplace(faker_A->next);
            faker_A=faker_A->next;
        }
        
        auto faker_B = new ListNode();
        faker_B->next=headB;
        while (faker_B->next!=nullptr)
        {
            if (setNodes.count(faker_B->next))
            {
                return faker_B->next;
            }
            faker_B=faker_B->next;
        }
        
        return nullptr; 
    }
};
// @lc code=end

