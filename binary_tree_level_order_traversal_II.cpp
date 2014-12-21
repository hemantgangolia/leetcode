/*
https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
            
            if (cur == dummy) {
                if (temp.empty()) break;
                res.push_back(temp);
                temp.clear();
                q.push(dummy);
            } else {
                temp.push_back(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};