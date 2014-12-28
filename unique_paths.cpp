/*
https://oj.leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        m-=1; n-=1;
        int N = m+n;
        int R = m > n ? m : n;
        long long int res = 1;
        for (int i = R+1; i<=N; i++) {
            res *= i;
            res /= i-R;
        }
        return res;
    }
};
