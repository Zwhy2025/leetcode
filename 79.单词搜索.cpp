/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
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

class Solution {
public:

    bool backtracking(vector<vector<char>>& board, string& word,
        int row, int col, int index)
    {
        // 边界判定以及当前值判定
        if (row<0 || row>= board.size() || col < 0 || col >= board[0].size()
            || board[row][col] != word[index]) {
            return false;
        }
        // 回溯算法终止条件
        if (index == word.size() - 1) {
            return true;
        }

        char temp = board[row][col];
        board[row][col] = '/';
        // 找到一条路径一直返回到顶端
        bool result = ( backtracking(board, word, row+1, col, index+1) ||
                        backtracking(board, word, row-1, col, index+1) ||
                        backtracking(board, word, row, col+1, index+1) ||
                        backtracking(board, word, row, col-1, index+1));
        // 标记使用过的单元,防止循环引用
        board[row][col] = temp;

        return result;

    }

    bool exist(vector<vector<char>>& board, string word)
    {
        // 找到字符串开头的字符后进行回溯
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtracking(board, word, i, j, 0)) {
                    return true;
                } 
            }
        }
        return false;

    }
};
// @lc code=end

