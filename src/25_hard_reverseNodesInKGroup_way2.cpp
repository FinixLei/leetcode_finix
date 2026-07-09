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

    ListNode* reverseList(ListNode* head, ListNode* tail) {
        if (head == nullptr || tail == nullptr) return head;

        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = nullptr;
        ListNode* nextptr = nullptr;

        while (p2 != tail && p2 != nullptr) {
            p3 = p2->next;
            p2->next = p1;
            if (p1 == head) p1->next = nullptr;
            p1 = p2;
            p2 = p3;
        }
        if (p2 == tail) {
            nextptr = p2->next;
            p2->next = p1;
            if (p1 == head) p1->next = nullptr;
        }
        return nextptr;
    }

    vector<pair<ListNode*, ListNode*>> findNodeGroups(ListNode* head, int k) {
        vector<pair<ListNode*, ListNode*>> vec;
        ListNode *p = head;
        while (p != nullptr) {
            int count = 0;
            ListNode * start = p;
            while(count < k && p!=nullptr) {
                p = p->next;
                count ++;
            }
            ListNode * end = p;
            vec.push_back(make_pair(start, end));
        }
        return vec;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        if (head == nullptr || head->next == nullptr) return head;

        vector<pair<ListNode*, ListNode*>> vec = findNodeGroups(head, k);
        if (vec.size() == 0) {
            cout << "vec.size() is 0" << endl;
            return head;
        }

        for (auto node_pair : vec) {
            cout << node_pair.first << ", " << node_pair.second << endl;

        }
        return head;
    }
};
