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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //虚拟头节点,更好处理当前节点
        auto fake = new ListNode();
        fake->next = head;

        //构造快慢指针
        auto front = fake;
        auto back = fake;

        // 快指针先走
        while (n--){
            front=front->next;
        }
        
        while (front)
        {
            // 快指针先走一步,如果为空,
            // 则back下一个就是我们需要处理的节点
            front=front->next;
            if(!front){
                // 我们一定可以确定back的下一个节点不为空
                // 因为题目中的n最小为1
                back->next =back->next->next;
                break;
            }
            // 无事发生则继续走
            back=back->next;
        }
        //  记得返回的是虚拟头节点的下一个
        return fake->next;
    }
};
// @lc code=end

