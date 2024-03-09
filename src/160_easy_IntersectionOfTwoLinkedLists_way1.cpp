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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> s1 = {}, s2 = {};
        ListNode *h1 = headA;
        ListNode *h2 = headB;

        while (h1 != nullptr && h2 != nullptr) {
            if (h1 == h2) return h1;
            if (s1.contains(h2)) return h2;
            if (s2.contains(h1)) return h1;
            
            s1.insert(h1);
            s2.insert(h2);
            h1 = h1->next;
            h2 = h2->next;
        }

        while (h1 != nullptr) {
            if (s2.contains(h1)) return h1;
            h1 = h1->next;
        }

        while (h2 != nullptr) {
            if (s1.contains(h2)) return h2;
            h2 = h2->next;
        }

        return nullptr;
    }
};