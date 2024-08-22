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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif // LISTNODE_H

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        auto dummy = new ListNode();
        dummy->next = head;

        auto fast = dummy;
        auto slow = dummy;

        while (n--) {
            if (!fast) {
                return nullptr;
            }
            fast = fast->next;
        }

        // 今天百度一面中需要手写数据结构以及自定义方法
        // 一定要注意边界条件,否者会出现段错误,出错映像会很差
        while (fast) {
            fast = fast->next;
            if (!fast) {
                slow->next = slow->next->next;
                break;
            }
            slow = slow->next;
        }

        return dummy->next;
    }
};
// @lc code=end

