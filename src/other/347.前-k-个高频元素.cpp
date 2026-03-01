/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
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
#include <memory>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {   
        // 统计对于元素出现次数,数据收集std::pair<int,int>
        std::unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }

        // 定义仿函数
        auto comp = [](const std::pair<int,int>& a,const std::pair<int,int>& b){
            return a.second > b.second;
        };

        // 构造优先级队列,并自定义规则
        std::priority_queue<std::pair<int,int>,
                            std::vector<std::pair<int,int>>,
                            decltype(comp)
                            >  pri_que(comp);

        // 压入队列 进行筛选
        for(const auto& it : map){
            pri_que.push(it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }

        // 倒序获取
        std::vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        
        return result;
    }
};
// @lc code=end
