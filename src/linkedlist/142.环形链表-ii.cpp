// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        auto sNodeSet = unordered_set<ListNode*>();
        auto pos = head;
        while (pos)
        {   
            //检查哈希散列表里面是不是有重复值,O(1)
            if(sNodeSet.count(pos)){
                return pos;
            }
            //遍历每个元素O(n)
            sNodeSet.emplace(pos);
            pos = pos->next;
        }
        return nullptr;
        
    }
};
// @lc code=end

