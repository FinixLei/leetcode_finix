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
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }

        int sum = 0;
        if (l1 == NULL && l2 != NULL)
            sum = l2->val;
        else if (l1 != NULL && l2 == NULL)
            sum = l1->val;
        else
            sum = l1->val + l2->val;
        
        int cur_val = sum >= 10 ? sum - 10 : sum;
        int step    = sum >= 10 ? 1 : 0;

        ListNode * head = new ListNode(cur_val);
        ListNode * p = head;
        l1 = l1->next;
        l2 = l2->next;
        
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL && l2 != NULL) 
                sum = l2->val + step;
            else if (l1 != NULL && l2 == NULL) 
                sum = l1->val + step;
            else 
                sum = l1->val + l2->val + step;
        
            cur_val = sum >= 10 ? sum - 10 : sum;
            step    = sum >= 10 ? 1 : 0;
            
            p->next = new ListNode(cur_val); 
            p = p->next;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        
        if (step > 0) p->next = new ListNode(step);
        
        return head;
    }
};
