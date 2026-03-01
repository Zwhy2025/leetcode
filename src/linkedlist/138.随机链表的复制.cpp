/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

 // @lc code=start
 /*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* next;
     Node* random;

     Node(int _val) {
         val = _val;
         next = NULL;
         random = NULL;
     }
 };
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
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
#endif // LISTNODE_H

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mapOld2New;
        Node* it = head;

        // 先进行一次索引表的建立
        while (it) {
            mapOld2New[it] = new Node(it->val);
            it = it->next;
        }

        it = head;
        while (it) {
            // 右边的值是新节点的值,左边是新节点的索引
            mapOld2New[it]->next = mapOld2New[it->next];
            mapOld2New[it]->random = mapOld2New[it->random];
            it = it->next;
        }
        return mapOld2New[head];
    }
};
// @lc code=end

