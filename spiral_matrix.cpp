/*
https://oj.leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int len = matrix.size();
        vector<int> res;
        if (len == 0) return res;
        int l = 0, r = matrix[0].size(), u = 0, d = len;
        
        vector<vector<int> > vs (len, vector<int> (matrix[0].size(), 0));
                
    	int i=0, j=0;
    	while (l < r && u < d) {
    		for (i=u, j = l; j < r; j++)
    			if (!vs[i][j]) {
    			    res.push_back(matrix[i][j]);
    			    vs[i][j] = 1;
    			}
    		u++;
    		for (j = r-1, i = u; i < d; i++)
    			if (!vs[i][j]) {
    			    res.push_back(matrix[i][j]);
    			    vs[i][j] = 1;
    			}
    		r--;
    		for (i = d-1, j = r-1; j >= l; j--)
    			if (!vs[i][j]) {
    			    res.push_back(matrix[i][j]);
    			    vs[i][j] = 1;
    			}
    		d--;
    		for (j = l, i = d-1; i >= u; i--)
    			if (!vs[i][j]) {
    			    res.push_back(matrix[i][j]);
    			    vs[i][j] = 1;
    			}
    		l++;
    	}
    	
        return res;
    }
};
