/*
https://oj.leetcode.com/problems/path-sum-ii/

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void hasPathSum(TreeNode *root, int sum, vector<int> & temp, vector<vector<int> > & res) {

        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL && sum == root->val) {
            temp.push_back(root->val);
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        hasPathSum(root->left, sum-root->val, temp, res);
        hasPathSum(root->right, sum-root->val, temp, res);
        temp.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> temp;
        hasPathSum(root, sum, temp, res);
        return res;
    }
};