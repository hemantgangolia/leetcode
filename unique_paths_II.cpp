/*
https://oj.leetcode.com/problems/unique-paths-ii/

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0 || obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid[0].size();
        
        vector<vector<int> > mat(m, vector<int> (n, 0));
        mat[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                if (i > 0) mat[i][j] += mat[i-1][j];
                if (j > 0) mat[i][j] += mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
    }
};
