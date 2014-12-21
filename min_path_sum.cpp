/*
https://oj.leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > minPath(grid);
        for (int i = 1; i < m; i++) {
            minPath[i][0] = minPath[i-1][0] + grid[i][0];
        }
        
        for (int i = 1; i < n; i++) {
            minPath[0][i] = minPath[0][i-1] + grid[0][i];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                minPath[i][j] = min(minPath[i-1][j] + grid[i][j], minPath[i][j-1] + grid[i][j]);
            }
        }
        return minPath[m-1][n-1];
    }
};