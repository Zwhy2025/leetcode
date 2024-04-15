// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
using namespace std;

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        //增加虚拟头节点,统一处理真·头节点行为
        auto faker =new ListNode(0);
        faker->next = head;
        // 增加移动指针,因返回结果时,需要返回原始链表头节点
        auto pos = faker;
        // 增加虚拟头之后,所有pos->next 则为遍历整个链表
        while (pos->next != nullptr)
        {
            // 如果下一个节点为目标值,将下下个节点嫁接过来,
            // 无论为空还是咋样,都被循环边界判定
            if (pos->next->val == val)
            {
                pos->next = pos->next->next;
            }
            // 如果不为目标值,则移动指针向前
            else
            {
                pos = pos->next;
            }
        }
        //记得返回原始链表头
        return faker->next;
    }
};
// @lc code=en              
