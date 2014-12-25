/*
https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *helper(vector<int> &num, int l, int r) {
        if (l <= r) {
            int mid = l + (r-l)/2;
            TreeNode * t = new TreeNode (num[mid]);
            t->left = helper(num, l, mid-1);
            t->right = helper(num, mid+1, r);
            return t;
        }
        return NULL;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return helper(num, 0, num.size()-1);
    }
};
