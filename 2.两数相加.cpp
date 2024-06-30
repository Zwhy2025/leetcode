/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(-1);
        auto it = &dummy;

        int remain = 0;
        while (l1 || l2 || remain) {
            // 将求和分散到各部分
            // 不用对 l1 和 l2 和 remain 分别讨论
            // 对三种特殊情况统一讨论
            // 并兼容通用情况
            int sum = remain;
            
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            remain = sum / 10;
            it->next = new ListNode(sum % 10);
            it = it->next;
        }
        return dummy.next;
    }
};
// @lc code=end

#include <gtest/gtest.h>

// TEST(addTwoNumbers,  test1)
// {
//     Solution s;
//     ListNode *l1 = new ListNode(9);
//     l1->next = new ListNode(9);
//     l1->next->next = new ListNode(9);
//     l1->next->next->next = new ListNode(9);
//     l1->next->next->next->next = new ListNode(9);
//     l1->next->next->next->next->next = new ListNode(9);
//     l1->next->next->next->next->next->next = new ListNode(9);

//     ListNode *l2 = new ListNode(9);
//     l2->next = new ListNode(9);
//     l2->next->next = new ListNode(9);
//     l2->next->next->next = new ListNode(9);

//     ListNode *res = s.addTwoNumbers(l1, l2);
//     EXPECT_EQ(res->val, 8);
//     EXPECT_EQ(res->next->val, 9);
//     EXPECT_EQ(res->next->next->val, 9);
//     EXPECT_EQ(res->next->next->next->val, 9);
//     EXPECT_EQ(res->next->next->next->next->val, 0);
//     EXPECT_EQ(res->next->next->next->next->next->val, 0);
//     EXPECT_EQ(res->next->next->next->next->next->next->val, 0);
//     EXPECT_EQ(res->next->next->next->next->next->next->next->val, 1);
// }
// 测试数据 [2,4,9]
// [5,6,4,9]
TEST(addTwoNumbers, test2)
{
    Solution s;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(9);

    ListNode* res = s.addTwoNumbers(l1, l2);
    EXPECT_EQ(res->val, 7);
    EXPECT_EQ(res->next->val, 0);
    EXPECT_EQ(res->next->next->val, 4);
    EXPECT_EQ(res->next->next->next->val, 0);
    EXPECT_EQ(res->next->next->next->next->val, 1);
}