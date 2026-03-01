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
