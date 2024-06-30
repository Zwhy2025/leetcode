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
        ListNode dummy(-1); //哨兵
        ListNode* it = &dummy;

        // 同时遍历两个链表
        // 取得两个节点中最小的节点
        // 不管怎么样记得指针往前对齐
        while(list1 && list2)
        {
            if(list1->val <= list2->val){
                it->next =list1;
                list1 = list1->next;
            }else{
                it->next = list2;
                list2 = list2->next;
            }
            it = it->next;
        }
        // 剩下节点直接拼接到后面
        // 经过上述遍历 只会留下大于等于最后另一个链表的所有元素的链表
       it->next = list1 ? list1 : list2;
       return dummy.next;
    }
};
// @lc code=end

#include <gtest/gtest.h>

/**
Testcase
[-10,-10,-9,-4,1,6,6]
[-7]
Expected Answer
[-10,-10,-9,-7,-4,1,6,6]
 */
TEST(Test21, SimpleTest){
    Solution s;
    ListNode* l1 = new ListNode(-10, new ListNode(-10, new ListNode(-9, new ListNode(-4, new ListNode(1, new ListNode(6, new ListNode(6)))))));
    ListNode* l2 = new ListNode(-7);
    ListNode* res = s.mergeTwoLists(l1, l2);
    vector<int> ans = {-10,-10,-9,-7,-4,1,6,6};
    for (int i = 0; i < ans.size(); i++)
    {
        EXPECT_EQ(res->val, ans[i]);
        res = res->next;
    }
}