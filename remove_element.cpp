/*
https://oj.leetcode.com/problems/remove-element/

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n<=0) return n;
        int i = 0, j = n-1;
        while(true) {
            while(i<=j && A[i]!= elem) i++;
            while(i<=j && A[j]== elem) j--;
            if(i >= j) break;
            A[i++] = A[j--];
        }
        return i;
    }
};