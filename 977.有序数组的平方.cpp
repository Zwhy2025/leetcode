// @before-stub-for-debug-begin
#include <vector>
#include <string>


using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
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
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        auto start = nums.begin();
        auto end = nums.end()-1;
        std::vector<int> temp;
        while(start!=end){
            int e = (*end)*(*end);
            int s = (*start)*(*start);
            if(e>s){
                temp.emplace_back(e);
                end--;
            }else{
                temp.emplace_back(s);
                start++;
            }
        }

        int e = (*end)*(*end);
        if(nums.size()!=temp.size()){
            temp.emplace_back(e);
        }

        std::reverse(temp.begin(),temp.end());
        return temp;
    }
};
// @lc code=end
