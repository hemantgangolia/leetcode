/*
https://oj.leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/


/*
Step 1: Find the largest index k, such that A[k]<A[k+1]. If not exist, this is the last permutation. (in this    problem just sort the vector and return.)
Step 2: Find the largest index l, such that A[l]>A[k].
Step 3: Swap A[k] and A[l].
Step 4: Reverse A[k+1] to the end.
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size()-1, n = num.size();
        while (i > 0 && num[i-1] >= num[i]) {
            i--;
        } 
        if (i==0){
            sort(num.begin(), num.end());
            return;
        }
        int l;
        for (int j = i; j < n; j++) {
            if (num[j] > num[i-1]) {
                l = j;
            }
        }       
        swap(num[l], num[i-1]);
        sort(num.begin()+i, num.end());
            
    }
};