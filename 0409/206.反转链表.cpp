/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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


    ListNode* reverseList(ListNode* head) {
        
        //指针左
        ListNode* left = nullptr; 
        // 指针右
        ListNode* right = head;
        // 中间节点
        ListNode* tmp;

        // 有时候分不清楚是判断当前节点 还是下一个几点为临界条件
        while(right)
        {
            //保存下一个节点,先中断,后续回溯到此位置
            tmp =right->next;
            // 插入到返回节点后面
            right->next =left;
            // 指针后移保证链条增长
            left=right;
            // 回溯到正常链表,进行下一次循环
            right=tmp;

        }
        return left;

    }
};
// @lc code=end

