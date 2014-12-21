/*
https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    
    void flatten(TreeNode *root) {
        while(root) {
            if (root->left) {
                TreeNode * temp = root->left;
                while(temp->right) {
                    temp = temp->right;
                }
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};