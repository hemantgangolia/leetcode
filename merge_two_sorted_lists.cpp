/*
https://oj.leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *res = NULL, *temp = NULL;
        
        if (l1->val <= l2->val) {
            res = l1;
            l1 = l1->next;
        } else {
            res = l2;
            l2 = l2->next;
        }
        temp = res;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            } else {
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        }
        
        if (l1) {
            res->next = l1;
        }
        
        if (l2) {
            res->next = l2;
        }
        
        return temp;
    }
};
