/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
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

class MyLinkedList
{
public:
    int val;
    MyLinkedList *next;
    MyLinkedList(int value) : val(value), next(nullptr) {}
    MyLinkedList() : val(0), next(nullptr) {}

    int get(int index)
    {
        auto pos = this->next;
        int res = -1;
        while (pos != nullptr)
        {
            if (res < index)
            {
                res++;
                pos = pos->next;
            }
            else if (res == index)
            {
               return res;
            }
            else
            {
                return -1;
            }
        }
        return res;
    }

    void addAtHead(int val)
    {
        auto temp = this;
        auto head = new MyLinkedList(val);
        head->next = temp;
        this->next;
        
    }

    void addAtTail(int val)
    {
    }

    void addAtIndex(int index, int val)
    {
    }

    void deleteAtIndex(int index)
    {
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
