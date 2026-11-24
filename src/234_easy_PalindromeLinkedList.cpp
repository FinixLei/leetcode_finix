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
private:
    ListNode* reverseLink(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        while (p2) {
            ListNode* tmp = p2->next;
            p2->next = p1;
            p1 = p2; 
            p2 = tmp;
        }
        head->next = nullptr;
        return p1;
    }

    // return is: 1. the previous node of slow pointer, 2. case number
    // case number: 1 means node number is even, 2 means node number is odd
    pair<ListNode*, int> findMiddle(ListNode* head) {
        ListNode* prev_slow = nullptr;
        ListNode* slow = head;
        ListNode* quick = head;
        while(quick->next) {
            prev_slow = slow;
            slow = slow->next;
            quick = quick->next;
            if (quick->next == nullptr) {
                cout << "Get to case-1" << endl;
                return make_pair(prev_slow, 1);
            }
            quick = quick->next;
        }
        return make_pair(prev_slow, 2);
    }
    bool checkSame(ListNode* h1, ListNode* h2) {
        while (h1 && h2) {
            if (h1->val != h2->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return (h1 == nullptr && h2 == nullptr);
    }
    void printChain(ListNode* head) {
        while (head->next) {
            cout << head->val << " => ";
            head = head->next;
        }
        cout << head->val << endl;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return false;
        if (head->next == nullptr) return true;
        if (head->next->next == nullptr) return head->val == head->next->val;
        pair<ListNode*, int> pr = findMiddle(head);

        ListNode* prev_slow = pr.first;
        ListNode* slow = prev_slow->next;
        bool res = false;

        if (pr.second == 1) {  // case-1: node number is even, and slow is the first node the next half chain
            prev_slow->next = nullptr;
            ListNode* h2 = reverseLink(slow);
            res = checkSame(head, h2);
            // recover 
            // prev_slow->next = reverseLink(h2);
            // printChain(head);
        }
        else {  // case-2: node number is odd, slow is the middle of the whole chain
            prev_slow->next = nullptr; 
            ListNode* slow_next = slow->next;
            slow->next = nullptr;
            ListNode* h2 = reverseLink(slow_next);
            res = checkSame(head, h2);
            // recover
            // prev_slow->next = slow;
            // slow->next = reverseLink(h2);
            // printChain(head);
        }
        return res;
    }
};
