/*
https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *helper(ListNode *&head, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int mid = l + (r-l)/2;
        TreeNode *leftChild = helper(head, l, mid-1);
        TreeNode *parent = new TreeNode (head->val);
        parent->left = leftChild;
        head = head->next;
        parent->right = helper(head, mid+1, r);
        return parent;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        ListNode *end = head;
        int count = 1;
        while (end->next) {
            end = end->next;
            count++;
        }
        return helper(head, 0, count-1);
        
    }
};
