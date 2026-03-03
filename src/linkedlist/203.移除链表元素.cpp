// @before-stub-for-debug-begin
#include <string>
#include <vector>

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
 *     ListNode() : val(0), next(nullptr) {
        // TODO
    }
 *     ListNode(int x) : val(x), next(nullptr) {
        // TODO
    }
 *     ListNode(int x, ListNode *next) : val(x), next(next) {
        // TODO
    }
 * };
 */

#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr)
  {
    // TODO
  }
  ListNode(int x) : val(x), next(nullptr)
  {
    // TODO
  }
  ListNode(int x, ListNode *next) : val(x), next(next)
  {
    // TODO
  }
};

#endif // LISTNODE_H

#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    // TODO

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *root = dummy;

    while (dummy->next != nullptr)
    {
      if (dummy->next->val == val)
      {
        dummy->next = dummy->next->next;
      }
      else
      {
        dummy = dummy->next;
      }
    }
    return root->next;
  }
};

// @lc code=end
