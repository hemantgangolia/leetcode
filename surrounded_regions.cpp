/*
https://oj.leetcode.com/problems/surrounded-regions/

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    
    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;
        
        int m = board.size(), n = board[0].size();
        queue<pair<int,int> > q;
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.push(pair<int,int> (0,j));
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[m-1][j] == 'O') {
                q.push(pair<int,int> (m-1,j));
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push(pair<int,int> (i,0));
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][n-1] == 'O') {
                q.push(pair<int,int> (i,n-1));
            }
        }
        
        while (!q.empty()) {
            pair<int,int> temp = q.front(); q.pop();
            
            int x = temp.first, y = temp.second;
            board[x][y] = 'P';
            
            if (x > 0 && board[x-1][y] == 'O') {
                q.push(pair<int,int>(x-1,y));
            }
            if (y > 0 && board[x][y-1] == 'O') {
                q.push(pair<int,int>(x,y-1));
            }
            if (x < m-1 && board[x+1][y] == 'O') {
                q.push(pair<int,int>(x+1,y));
            }
            if (y < n-1 && board[x][y+1] == 'O') {
                q.push(pair<int,int>(x,y+1));
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'P') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};