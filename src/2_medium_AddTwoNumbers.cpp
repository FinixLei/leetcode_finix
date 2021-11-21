/*
    You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        int inc = 0;
        int tmp = l1->val + l2->val;
        inc = tmp >= 10 ? 1 : 0;
        tmp = tmp >= 10 ? (tmp-10) : tmp; 
        
        ListNode * head = new ListNode(tmp); 
        ListNode * p = head;
        l1 = l1->next;
        l2 = l2->next;
        
        while (l1 || l2) {
            if (l1 == nullptr) {
                tmp = l2->val + inc;
                l2 = l2->next;
            }
            else if (l2 == nullptr) {
                tmp = l1->val + inc;
                l1 = l1->next;
            }
            else {  // both are not nullptr
                tmp = l1->val + l2->val + inc;
                l1 = l1->next;
                l2 = l2->next;
            }
            inc = tmp >= 10 ? 1 : 0;
            tmp = tmp >= 10 ? (tmp-10) : tmp; 
            
            p->next = new ListNode(tmp);
            p = p->next;
        }
        
        if (inc > 0) p->next = new ListNode(inc);
        return head;
    }
};