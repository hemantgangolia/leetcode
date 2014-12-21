/*
https://oj.leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    
    int dfs(vector<vector<char> > &board, int i, int j, string word, int index, vector<vector<bool> > &visited) {
        if (index == word.length()) return true;
        visited[i][j] = true;
        int m = board.size(), n = board[0].size();
        bool flag = false;
        if (!flag && i > 0 && !visited[i-1][j] && board[i-1][j] == word[index]) {
            flag = flag || dfs(board, i-1, j, word, index+1, visited);
        }
        if (!flag && j > 0 && !visited[i][j-1] && board[i][j-1] == word[index]) {
            flag = flag || dfs(board, i, j-1, word, index+1, visited);
        }
        if (!flag && i+1 < m && !visited[i+1][j] && board[i+1][j] == word[index]) {
            flag = flag || dfs(board, i+1, j, word, index+1, visited);
        }
        if (!flag && j+1 < n && !visited[i][j+1] && board[i][j+1] == word[index]) {
            flag = flag || dfs(board, i, j+1, word, index+1, visited);
        }
        visited[i][j] = 0;
        return flag;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || word.empty()) return false;
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 1, visited)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};