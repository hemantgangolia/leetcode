/*
https://oj.leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.top();
            q.pop();
            if (temp == NULL) continue;
            res.push_back(temp->val);
            q.push(temp->right);
            q.push(temp->left);
        }
        return res;
    }
};