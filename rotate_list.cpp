/*
https://oj.leetcode.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return head;
        
        int len = 1;
        ListNode* last = head;
        while (last->next != NULL) {
            len++;
            last = last->next;
        }
        k = k%len;
        if (k == 0) {
            return head;
        }
        ListNode * temp = head;
        last = head;
        while(k--) {
            last = last->next;
        }
        while (last->next != NULL) {
            last = last->next;
            temp = temp->next;
        }
        ListNode * res = temp->next;
        temp->next = NULL;
        last->next = head;
        return res;
    }
};