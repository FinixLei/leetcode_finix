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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;

        while (head != nullptr && head->val == val) {
            ListNode * tmp = head;
            head = head->next;
            delete(tmp);
        }
        if (head == nullptr) return nullptr;
        
        ListNode * currHead = head;
        ListNode * pre = head;
        head = head->next;

        while (head != nullptr) {
            if (head->val == val) {
                pre->next = head->next;
                delete(head);
                head = pre->next;
            }
            else {
                pre = head;
                head = head->next;
            }
        }
        return currHead;
    }
};