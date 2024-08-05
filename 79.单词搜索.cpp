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

    bool backtracking(vector<vector<char>>& board, string word, int index, int row, int col)
    {
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return  true;
        }

        char temp = board[row][col];
        board[row][col] = '/';
        bool res = (backtracking(board, word, index + 1, row + 1, col) ||
                    backtracking(board, word, index + 1, row, col + 1) ||
                    backtracking(board, word, index + 1, row - 1, col) ||
                    backtracking(board, word, index + 1, row, col - 1));
        board[row][col] = temp;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtracking(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

