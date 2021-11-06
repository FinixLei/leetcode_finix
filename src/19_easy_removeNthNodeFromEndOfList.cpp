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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        
        ListNode * t1 = head;
        for (int i=0; i<n; i++) {
            t1 = t1->next; 
            if (t1 == nullptr && i != n-1) return nullptr;
        }
        
        if (t1 == nullptr) {
            ListNode * tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        
        ListNode * t2 = head;
        ListNode * preT2 = nullptr;
        while (t1 != nullptr) {
            preT2 = t2;
            t2 = t2->next;
            t1 = t1->next;
        }
        
        preT2->next = t2->next;
        delete t2;
        return head;
    }
};
