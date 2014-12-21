/*
https://oj.leetcode.com/problems/maximum-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int res = A[0];
        int temp = A[0];
        for (int i = 1; i < n; i++) {
            temp = max(A[i], temp+A[i]);
            res = max(res, temp);
        }
        return res;
    }
};