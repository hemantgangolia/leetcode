/*
https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int len = num.size();
        int l = 0, r = len-1;
        int res = num[0];
        while (l < r) {
            int mid = l + (r-l)/2;
            if (num[mid] > num[mid+1]) {
                res = num[mid+1];
                break;
            } else if (num[l] < num[mid]) {
                l = mid+1;
                res = min(res, num[l]);
            } else {
                r = mid;
            }
        }
        return res;
    }
};