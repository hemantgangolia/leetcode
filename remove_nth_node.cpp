/*
https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head->next == NULL) return NULL;
        
        ListNode *temp = head, *last = head;
        while (n--) {
            last = last->next;
        }
        if (last == NULL) {
            return head->next;
        }
        while (last->next != NULL) {
            temp = temp->next;
            last = last->next;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};