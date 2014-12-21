/*
https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        stack<TreeNode*> q1, q2;
        q1.push(root);
        TreeNode *temp = NULL;
        vector<vector<int> > res;
        if (!root) return res;
        
        vector<int> vec;
        while (!q1.empty() || !q2.empty()) {
            while (!q1.empty()) {
                temp = q1.top();
                q1.pop();
                if(temp->left)q2.push(temp->left);
                if(temp->right)q2.push(temp->right);
                vec.push_back(temp->val);
            }
            if (!vec.empty()) res.push_back(vec);
            vec.clear();
            while (!q2.empty()) {
                temp = q2.top();
                q2.pop();
                if(temp->right)q1.push(temp->right);
                if(temp->left)q1.push(temp->left);
                vec.push_back(temp->val);
            }
            if (!vec.empty()) res.push_back(vec);
            vec.clear();
        }
        return res;
    }
};