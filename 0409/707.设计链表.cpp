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

    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int value) : val(value), next(nullptr) {}
    };

public:
    MyLinkedList()
    {
        _tHeadList = new ListNode(0);
        _size = 0;
    }

    int get(int index)
    {

        // 第一个条件是判断节点数量是不是小于index
        // 因为虚拟了头节点 所以要-1
        // 第二个条件就是正常判断范围了
        if (index > (_size - 1) || index < 0)
        {
            return -1;
        }

        // 到了这里就可以确定一定是有对应的index
        //  导航到第一个节点
        ListNode *pos = _tHeadList->next;
        // 进入循环一直找到目标节点
        // 找到后目标节点后 循环会终止 0
        // 注意 -1逻辑上也是false 应该是补码的原因
        while (index--)
        {
            pos = pos->next;
        }

        return pos->val;
    }

    void addAtHead(int val)
    {
        // 链表属性 永远是记录了头节点
        ListNode *node = new ListNode(val);
        node->next = _tHeadList->next;
        _tHeadList->next = node;
        _size++;
    }

    void addAtTail(int val)
    {
        // 只能遍历到末尾了
        ListNode *node = new ListNode(val);
        ListNode *pos = _tHeadList;
        // 虚拟头节点 确保了 pos 一定是存在的
        // 这样就不会出现崩溃的问题
        while (pos->next != nullptr)
        {
            // 一直索引到最末端
            pos = pos->next;
        }
        pos->next = node;
        _size++;
    }

    void addAtIndex(int index, int val)
    {
        // 大于索引插入不了
        if (index > _size)
            return;

        // 小于索引 插入最前端
        if (index < 0)
            index = 0;

        ListNode *node = new ListNode(val);
        ListNode *pos = _tHeadList;
        while (index--)
        {
            pos = pos->next;
        }
        // 如果插入位置在目标位置 则索引不需要变换

        // 在所索引位置之前插入节点
        node->next = pos->next;
        pos->next = node;
        _size++;
    }

    void deleteAtIndex(int index)
    {
        // 有了这些边界条件,后续可以少处理一些异常
        // 这些条件确保了index 一定是小于 等于 size的非零数字
        if (index >= _size || index < 0)
        {
            return;
        }

        // 导航到目标点
        ListNode *pos = _tHeadList;
        while (index--)
        {
            pos = pos->next;
        }
        // 注意
        // pos->next 才是我们需要的
        // 因为i--的特性

        ListNode *tmp = pos->next;
        pos->next = pos->next->next;

        // 计数器要自减
        _size--;
    }

private:
    ListNode *_tHeadList = nullptr;
    int _size;
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
