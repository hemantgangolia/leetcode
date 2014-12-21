/*
https://oj.leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k = m+n-1;
        m-=1;n-=1;
        while (m >= 0 && n>=0) {
            if (A[m] > B[n]) {
                A[k--] = A[m--];
            } else {
                A[k--] = B[n--];
            }
        }
        while (n >= 0) {
            A[k--] = B[n--];
        }
    }
};