/* 
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 */

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL && l2 != NULL) return l2;
    if (l1 != NULL && l2 == NULL) return l1;
    
    ListNode * head = NULL;
    if (l1->val <= l2->val) {
        head = l1;
        l1 = l1->next;
        head->next = NULL;
    }
    else {
        head = l2;
        l2 = l2->next;
        head->next = NULL;
    }
    
    ListNode * t = head;
    
    while (true) {
        if (l1 == NULL) {
            t->next = l2;
            break;
        }
        else if (l2 == NULL) {
            t->next = l1;
            break;
        }
        else {
            if (l1->val <= l2->val) {
                t->next = l1;
                l1 = l1->next;
                t = t->next;
                if (t) t->next = NULL;
            } 
            else {
                t->next = l2;
                l2 = l2->next;
                t = t->next;
                if (t) t->next = NULL;
            }
        }
    }
    
    return head;
}