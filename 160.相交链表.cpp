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
        // 构造哈希表 哈希表索引时间复杂度常量级
        auto setNodes = unordered_set<ListNode*>();

        //将一条链表所有的node地址加入哈希表
        auto pos = headA;
        while (pos)
        {
            setNodes.emplace(pos);
            pos=pos->next;
        }
        
        //遍历另一条链表
        auto res = headB;
        while (res)
        {   
            // 常量查找
            if (setNodes.count(res))
            {
                return res;
            }
            res=res->next;
        }
        
        return nullptr; 
    }
};
// @lc code=end

