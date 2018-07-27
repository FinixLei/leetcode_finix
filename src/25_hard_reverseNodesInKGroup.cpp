/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/


#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *h) 
{
    while(h!=NULL) {
        cout << h->val << ", ";
        h = h->next;
    }
    cout << endl;
}

class Solution {
public:
    void reverseLinkedList(ListNode *head, ListNode *end) {
        if (head == NULL || head->next == NULL || head == end) return;
        
        ListNode *p1, *p2;
        p1 = head;
        p2 = head->next;
        reverseLinkedList(head->next, end);
        p2->next = p1;
        p1->next = NULL;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        // ...->p0->a(p1)->b->c(p2)->p3->...
        // ...->p0->c(p2)->b->a(p1)->p3->...
        // .............c->b->a(p0)->p1->..p2->p3->...
        // so, 
        // step 1. Reverse a->b->c to c->b->a
        // step 2. p0->next = p2; 
        //         p1->next = p3;
        //         for the first reverse, there is no "p0->next = p2;"
        // step 3. p0 = p1;
        //         p1 = p3; 
        //         count k elements to get p2 and p3; 
        
        ListNode *p0 = NULL;
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *p3 = head;
        ListNode *new_head = head;
        
        while (p2->next != NULL) {
            p2 = p1;
            int count =1; 
            
            while(p2->next != NULL && count < k) {  // only break when count = k or p2->next = NULL
                p2 = p2->next;
                count ++;
            }
            
            if (count == k) { 
                bool exit_flag = p2->next == NULL ? true:false;
                p3 = p2->next;
                reverseLinkedList(p1, p2); 
                
                if (p0 != NULL) 
                    p0->next = p2;
                else // the first reverse
                    new_head = p2;
                
                p1->next = p3;
                p0 = p1;
                p1 = p3;
                
                if(exit_flag) return new_head;
            }
            else {  // count < k && p2->next == NULL
                return new_head;
            }
        }
        
        return new_head;
    }
};



int main()
{
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    // ListNode *p3 = new ListNode(3);
    // ListNode *p4 = new ListNode(4);
    // ListNode *p5 = new ListNode(5);
    
    p1->next = p2;
    // p2->next = p3;
    // p3->next = p4;
    // p4->next = p5;
    
    print_list(p1);
    
    Solution s;
    ListNode *h = s.reverseKGroup(p1, 2);
    print_list(h);

    
    return 0;
}