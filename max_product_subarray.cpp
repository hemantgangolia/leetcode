/*
https://oj.leetcode.com/problems/maximum-product-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(int A[], int n) {
         int maxProd = INT_MIN;
        int prod = 1;
        for(int i=0; i <n; i++)
        {
            prod = prod * A[i];
            maxProd = max(maxProd, prod);
            if (A[i] == 0)
                prod = 1;
        }
        
        prod = 1;
        for(int i=n-1; i >=0; i--)
        {
            prod = prod * A[i];
            maxProd = max(maxProd, prod);
            if (A[i] == 0)
                prod = 1;
        }
        
        return maxProd;
    }
};