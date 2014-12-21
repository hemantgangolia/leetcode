/*
https://oj.leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int i = 0, j = 0, k = n-1;
        while (j <= k) {
            if (A[j] == 0) {
                swap(A[i],A[j]);
                i++;
                j++;
            } else if (A[j] == 1) {
                j++;
            } else if (A[j] == 2) {
                swap(A[j], A[k]);
                k--;
            }
        }
    }
};