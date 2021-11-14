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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    if (l1 && l2 == nullptr) return l1;
    if (l1 == nullptr && l2) return l2;
    
    ListNode * head = nullptr;
    ListNode * p = nullptr;
    
    while (l1 || l2) {
        if (l1 && l2) {
            if (l1->val <= l2->val) {
                if (head) {
                    p->next = l1; 
                    l1 = l1->next; 
                    p = p->next;
                }
                else {  // head is nullptr 
                    head = l1;
                    l1 = l1->next;
                    p = head;
                }
            }
            else {
                if (head) {
                    p->next = l2; 
                    l2 = l2->next; 
                    p = p->next; 
                }
                else {  // head is nullptr 
                    head = l2;
                    l2 = l2->next; 
                    p = head;
                }
            }
        } 
        else if (l1 && l2 == nullptr) {
            p->next = l1;
            break;
        }
        else if (l1 == nullptr && l2) {
            p->next = l2;
            break;
        }
    }
    return head;
}