/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* _tFront;
    bool tick(ListNode* node){
        // 思路大概能知道,代码能力实现不了一个需求
        // return false 能传递到顶层,而 return true 需要继续判断
        // 全局变量是好方法,如果不会使用二级指针的话(或者用不好)
       if(node){
            if(!tick((node->next))) return false;
            if(node->val != _tFront->val) return false;
            _tFront = _tFront->next;
       }
       return true;
    }


    bool isPalindrome(ListNode* head) {;
        _tFront = head;
        return tick(head);
    }
};
// @lc code=end

