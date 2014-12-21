/*
https://oj.leetcode.com/problems/sqrtx/

Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x==0) {return 0;}
        if (x==1) {return 1;}
       
        double x0 = 1;
        double x1;
        while (true){
            x1 = (x0+ x/x0)/2;
            if (abs(x1-x0)<1){return x1;}
            x0=x1;
        }
         
    }
};