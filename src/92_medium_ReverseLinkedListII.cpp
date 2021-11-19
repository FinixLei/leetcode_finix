/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
    Input: head = [1,2,3,4,5], left = 2, right = 4
    Output: [1,4,3,2,5]
    
Example 2:
    Input: head = [5], left = 1, right = 1
    Output: [5]
    
Constraints:
    The number of nodes in the list is n.
    1 <= n <= 500
    -500 <= Node.val <= 500
    1 <= left <= right <= n
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode * finalHead = nullptr;
        ListNode * c1_end = nullptr, *c2_beg = nullptr, *c2_end = nullptr, *c3_beg = nullptr;
        int count = 1;
        ListNode * p = head; 
        while (count < left) {
            c1_end = p;
            p = p->next; 
            count ++;
        }
        c2_beg = p;
        
        while (count < right) {
            p = p->next;
            count ++;
        }
        c2_end = p;
        c3_beg = p->next;
        
        c2_end -> next = nullptr;
        
        // reverse c2_beg to c2_end
        p = c2_beg;
        ListNode * t1 = p->next;
        ListNode * t2 = t1->next;
        while (t2) {
            t1->next = p;
            p = t1;
            t1 = t2; 
            t2 = t2->next;
        }
        t1->next = p;
        
        if (c1_end) {
            c1_end->next = c2_end;
            finalHead = head;
        }
        else {
            finalHead = c2_end;
        }
        c2_beg -> next = c3_beg; 
        
        return finalHead;
    }
};