/*
https://oj.leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *first = head, *second = head->next;
        ListNode* prev= new ListNode (999);
        prev->next = head;
        head = second;
        while (first && second) {
            first->next = second->next;
            second->next = first;
            prev->next = second; 
            prev = first;
            first = first->next;
            if (first) {
                second = first->next;
            } else second = NULL;
            
        }
        return head;
    }
};