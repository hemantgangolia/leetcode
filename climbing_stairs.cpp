/*
https://oj.leetcode.com/problems/climbing-stairs/

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2, c;
        if (n<=2) return n;
        while (n > 2) {
            c = a+b;
            a = b;
            b = c;
            n--;
        }
        return b;
    }
};