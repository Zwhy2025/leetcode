/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        map<int,int> map;
        while (list1)
        {
            map[list1->val]++;
            list1 =list1->next;
        }

        while (list2)
        {
            map[list2->val]++;
            list2 =list2->next;
        }
        ListNode* head =new ListNode();
        auto res = head;
        for (auto &&m : map)
        {
           do
           {
             head->next = new ListNode(m.first);
             head = head->next;
           } while (--m.second);
        }
        
        return res->next;
    }
};
// @lc code=end

#include <gtest/gtest.h>
TEST(Test21, SimpleTest)
{
    Solution s;
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* ans = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4))))));
    EXPECT_EQ(s.mergeTwoLists(list1, list2), ans);
}