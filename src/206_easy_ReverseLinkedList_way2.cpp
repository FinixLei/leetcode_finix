class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode * p1 = head;
        ListNode * p2 = p1->next;
        ListNode * p3 = p2->next;
        p1->next = nullptr;

        while(p3) {
            p2->next = p1;
            p1 = p2;
            p2 = p3; 
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};