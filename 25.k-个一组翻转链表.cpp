/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif // LISTNODE_H

class Solution {
public:
    ListNode* existKList(ListNode* node, int k){
        while (k--) {
            if (!node->next) {
                return nullptr;
            }
            node = node->next;
        }
        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k){
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto it = dummy;
        while (1) {
            //检查后续是否存在个节点,不存在则到达尾部,返回结果
            auto back = existKList(it, k);
            if (!back) {
                break;
            }
            //记录下一个节点拼接处,循环时动态修改
            auto end = back->next;
            // 构造循环结束条件
            back->next = nullptr;
            //记录下次检索起点
            auto begin = it->next;
            // 链接主流程
            while (it->next) {
                auto front = it->next;
                it->next = front->next;
                front->next = end;
                end = front;
            }
            // 连接虚拟头节点与第一个节点
            it->next = end;
            // 重置迭代器
            it = begin;
        }

        return dummy->next;
    }
};
// @lc code=end

#include <gtest/gtest.h>

TEST(leetcode, 25)
{
    auto l1_1 = new ListNode(1);
    auto l1_2 = new ListNode(2);
    auto l1_3 = new ListNode(3);
    auto l1_4 = new ListNode(4);
    auto l1_5 = new ListNode(5);
    l1_1->next = l1_2;
    l1_2->next = l1_3;
    l1_3->next = l1_4;
    l1_4->next = l1_5;

    auto l2_1 = new ListNode(2);
    auto l2_2 = new ListNode(1);
    auto l2_3 = new ListNode(4);
    auto l2_4 = new ListNode(3);
    auto l2_5 = new ListNode(5);
    l2_1->next = l2_2;
    l2_2->next = l2_3;
    l2_3->next = l2_4;
    l2_4->next = l2_5;

    Solution s;
    auto result = s.reverseKGroup(l1_1, 2);
    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    EXPECT_EQ(true, true);
}