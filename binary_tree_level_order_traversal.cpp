/*
https://oj.leetcode.com/problems/binary-tree-level-order-traversal/

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        
        TreeNode * dummy = new TreeNode(0);
        queue<TreeNode*> q;
        q.push(root);
        q.push(dummy);
        vector<int> temp;
        while (!q.empty()) {
            TreeNode * cur = q.front();
            q.pop();
            if (!cur) continue;
            
            if (cur == dummy && !temp.empty()) {
                res.push_back(temp);
                temp.clear();
                q.push(dummy);
            } else {
                temp.push_back(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return res;
    }
};