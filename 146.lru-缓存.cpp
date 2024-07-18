/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
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
#include <list>
#include <cctype>
#include <cstring>
#include <cassert>
#include <numeric>
#include <memory>
using namespace std;

class LRUCache {
    using LRUList = std::list<std::pair<int,int>>;
    using LRUMap = std::unordered_map<int, LRUList::iterator>;
private:
    int _nCapacity;     ///< 缓存容量
    LRUMap _mapCache;   ///< 查询值,以及值对应在链表中的位置迭代器
    LRUList _listCache; ///< 存储键值对
public:
    LRUCache(int capacity):_nCapacity(capacity) {}
    
    int get(int key) {
        auto it = _mapCache.find(key);
        if (it == _mapCache.end()) {
            return -1;
        }
        // 链表(双向)的拼接操作,在已知迭代器的情况下,时间复杂度为O(1)
        // 这一步是为了实现LRU的特性,将最近访问的元素放到链表头部
        _listCache.splice(_listCache.begin(), _listCache, it->second);
        // 返回查询到的值
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = _mapCache.find(key);
        if (it != _mapCache.end()){
            // 这里的it 是同一个迭代器
            // 体现了数据的一致性,改变一个值另一个也会改变
            _listCache.splice(_listCache.begin(), _listCache, it->second);
            it->second->second = value;
        }else{
            //  如果缓存已满，移除最久未使用的项
            if(_mapCache.size() == _nCapacity){
                int nOldKey = _listCache.back().first;
                _listCache.pop_back();
                _mapCache.erase(nOldKey);
            }
            // 插入新项到链表头部,并记录迭代器
            _listCache.emplace_front(key,value);
            _mapCache[key] =_listCache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

