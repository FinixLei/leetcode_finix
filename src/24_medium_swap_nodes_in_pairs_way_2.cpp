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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode * newHead = head->next;

        ListNode *p1 = head;
        ListNode *p2 = p1->next;
        ListNode *p3 = p2->next;
        ListNode *pre = nullptr;

        while (p3 != nullptr && p3->next != nullptr) {
            p2->next = p1;
            p1->next = p3;
            if (pre) pre->next = p2;
            pre = p1;
            p1 = p3;
            p2 = p1->next;
            p3 = p2->next;
        }

        p2->next = p1;
        p1->next = p3;
        if (pre) pre->next = p2;

        return newHead;
    }
};