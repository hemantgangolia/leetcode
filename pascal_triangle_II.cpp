/*
https://oj.leetcode.com/problems/pascals-triangle-ii/

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        if (rowIndex == 0) return res;
        int n = rowIndex;
        long long int last = 1;
        for (int i = 1; i <= rowIndex; i++) {
            long long int x = (last * n)/i;
            n--;
            res.push_back((int)x);
            last = x;
        }
        return res;
    }
};