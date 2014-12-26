/*
https://oj.leetcode.com/problems/triangle/

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n==0) return 0;
        
        for (int i = 1; i < n; i++) {
            int j;
            triangle[i][0] += triangle[i-1][0];
            for (j = 1; j < i; j++) {
                triangle[i][j] = triangle[i][j] + min(triangle[i-1][j], triangle[i-1][j-1]);
            }
            triangle[i][j] += triangle[i-1][j-1];
        }
        
        int min_res = INT_MAX;
        for (int i = 0; i < n; i++) {
            min_res = min(min_res, triangle[n-1][i]);
        }
        return min_res;
    }
};
