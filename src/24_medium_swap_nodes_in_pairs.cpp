/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    void _swapPairs(ListNode* h) {
        if (h == NULL || h->next == NULL) return;
        
        ListNode* p1 = h;
        ListNode* p2 = h->next;
        ListNode* p3 = p2->next;
        
        if (p3 == NULL) return;
        
        // q -> p1 -> p2 -> p3 -> p4 -> x , swap p2 and p3
        ListNode* p4 = p3->next;
        p1->next = p3;
        p3->next = p2;
        p2->next = p4;
        // q -> p1 -> p3 -> p2 -> p4 -> x, swap p4 and x
        _swapPairs(p2); 
        
    }
    
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r = head->next->next; 
        p->next = r;
        q->next = p;
        _swapPairs(p);
        
        return q;
    }
};
