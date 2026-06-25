class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr && list2) return list2;
        if (list1 && list2 == nullptr) return list1;

        ListNode *head = nullptr;
        ListNode *p = nullptr;

        if (list1->val <= list2->val) {
            head = list1; 
            p = head;
            list1 = list1->next;
        }
        else {
            head = list2; 
            p = head;
            list2 = list2->next;
        }

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                p->next = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1 && list2 == nullptr) {
            p->next = list1;
        }
        else if (list1 == nullptr && list2) {
            p->next = list2;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        ListNode * list1 = lists[0];
        ListNode * head = list1;

        for (int i=1; i<lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};