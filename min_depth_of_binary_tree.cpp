/*
https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int res = 100000;
        if (root->left != NULL) res = min(res, minDepth(root->left));
        if (root->right != NULL) res = min(res, minDepth(root->right));
        return 1+res;
    }
};