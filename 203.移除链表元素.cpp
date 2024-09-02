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

        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto it = dummy;

        while (it->next) {

            if (it->next->val == val) {
                auto tmp = it->next;
                it->next = it->next->next;
                delete tmp;
            }
            else {
                it = it->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=en              
