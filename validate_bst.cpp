/*
https://oj.leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
 
 #define lli long long int
class Solution {
public:
    bool helper(TreeNode *root, lli l_bound, lli r_bound) {
        if (!root) return true;
        if (root->val > l_bound && root->val < r_bound) {
            return helper(root->left, l_bound, (lli)root->val) && helper(root->right, (lli)root->val, r_bound);
        }
            
        return false;
    }
    
    bool isValidBST(TreeNode *root) {
        return helper(root, (lli)INT_MIN-1, (lli)INT_MAX+1);
    }
    
};
