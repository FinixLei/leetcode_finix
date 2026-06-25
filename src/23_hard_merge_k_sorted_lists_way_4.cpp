class Solution {
public:
    struct NodeCmp {
        bool operator()(ListNode *a, ListNode *b) const {
            return a->val > b->val;
        }
    };

    ListNode * mergeKLists(vector<ListNode *>& vec) {
        priority_queue<ListNode*, vector<ListNode *>, NodeCmp> pq;
        for (ListNode* p : vec) {
            if(p) {
                pq.push(p);
            }
        }

        if (pq.empty()) {
            return nullptr;
        }

        ListNode * head = pq.top();
        ListNode * t = head;
        pq.pop();
        if (t->next) {
            pq.push(t->next);
        }

        while (!pq.empty()) {
            ListNode * tmp = pq.top();
            pq.pop();
            if (tmp->next) {
                pq.push(tmp->next);
            }
            t->next = tmp;
            t = t->next;
        }

        return head;
    }
};

class Solution {
public:
    struct NodeCmp {
        bool operator()(ListNode *a, ListNode *b) const {
            return a->val > b->val;
        }
    };

    ListNode * mergeKLists(vector<ListNode *>& vec) {
        priority_queue<ListNode*, vector<ListNode *>, NodeCmp> pq;
        for (ListNode* p : vec) {
            if(p) {
                pq.push(p);
            }
        }
        if (pq.empty()) return nullptr;

        ListNode dummy(0);
        ListNode * curr = &dummy;

        while (!pq.empty()) {
            ListNode * tmp = pq.top();
            pq.pop();
            if (tmp->next) {
                pq.push(tmp->next);
            }
            curr->next = tmp;
            curr = curr->next;
        }
        return dummy.next;
    }
};