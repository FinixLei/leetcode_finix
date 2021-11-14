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
                        p = p->next;
                        l1 = l1->next; 
                    }
                    else {  // head is nullptr 
                        head = l1;
                        p = head;
                        l1 = l1->next;
                    }
                }
                else {
                    if (head) {
                        p->next = l2; 
                        p = p->next; 
                        l2 = l2->next; 
                    }
                    else {  // head is nullptr 
                        head = l2;
                        p = head;
                        l2 = l2->next; 
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
        
    void print_list(ListNode * h) {
        if(!h) cout << "empty list" << endl;
        cout << "list: ";
        while (h) {
            cout << h->val << " ";
            h = h->next;
        }
        cout << endl;
    }

    ListNode * _sort(ListNode * beg, ListNode * end) {
        if (beg == nullptr || beg == end || beg->next == nullptr) return beg;
        
        ListNode * p1 = beg; 
        ListNode * p2 = beg->next->next; 
        
        while (p2) {
            p1 = p1->next; 
            p2 = p2->next; 
            if (p2 == nullptr) break;
            p2 = p2->next; 
        }
        
        ListNode * secondStart = p1->next; 
        p1->next = nullptr;
        
        ListNode * h1 = _sort(beg, p1);
        ListNode * h2 = _sort(secondStart, end);
        ListNode * h = mergeTwoLists(h1, h2);
        return h;
    }


    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode * lastNode = head;
        while(lastNode->next) lastNode = lastNode->next;
        
        ListNode * result = _sort(head, nullptr);
        return result;
    }
};