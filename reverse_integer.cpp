/*
https://oj.leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        bool neg = false;
        if (x < 0) {
            x = -x;
            neg = true;
        }
        
        int res = 0;
        while (x > 0) {
            res = res*10 + x%10;
            x = x/10;
        }
        if (neg) res = -res;
        
        return res;
    }
};