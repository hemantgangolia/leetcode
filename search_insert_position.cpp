/*
https://oj.leetcode.com/problems/search-insert-position/

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                l = mid+1;                
            } else {
                r = mid;
            }
        }
        return r;
    }
};