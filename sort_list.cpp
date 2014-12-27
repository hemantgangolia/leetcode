/*
https://oj.leetcode.com/problems/sort-list/

Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *merge(ListNode *l1, ListNode *l2) {
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

    void getMidNode(ListNode *&head) {
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            head = head->next;
            fast = fast->next->next;
        }
    }
    
    void mergeSort(ListNode *&head, int l, int r) {
        if (l < r) {
            int mid = l + (r-l)/2;
            ListNode *a = head, *b = head;
            getMidNode(b);
            ListNode *temp = b;
            b = b->next;
            temp->next = NULL;
            mergeSort(a, l, mid);
            mergeSort(b, mid+1, r);
            head = merge(a, b);
        }
    }

    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        ListNode *end = head;
        int n = 0;
        while (end->next) {
            n++;
            end = end->next;
        }
        mergeSort(head, 0, n);
        return head;
    }
};
