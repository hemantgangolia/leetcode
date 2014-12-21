/*
https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    void helper (TreeNode *root, int temp, int & res) {
        if (!root->left && !root->right) {
            res += temp+root->val;
            return;
        }
        if (root->left) helper(root->left, (temp+root->val)*10, res);
        if (root->right) helper(root->right, (temp+root->val)*10, res);
    }
    
    int sumNumbers(TreeNode *root) {
        int res = 0;
        if (root == NULL) return 0;
        helper(root, 0, res);
        return res;
    }
};