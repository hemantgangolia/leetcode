/*
https://oj.leetcode.com/problems/single-number-ii/

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Solution taken from http://yucoding.blogspot.in/2014/10/single-number-ii.html
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int t1 = 0;
        int t2 = 0;
        int t3 = 0;
         
        for (int i = 0; i < n; i++){
            t1 = t1 ^ A[i];
            t2 = t2 | ((t1^A[i]) & A[i]);
            t3 = ~(t1 & t2);
            t1 = t1 & t3;
            t2 = t2 & t3;
        }
         
        return t1;
    }
};
