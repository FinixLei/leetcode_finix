class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        ListNode* head = nullptr;
        ListNode* p = nullptr;

        int minVal = INT_MAX;
        for (auto node : lists) {
            if (node->val < minVal) {
                minVal = node->val;
            }
        }
        for (int i=0; i<lists.size(); i++) {
            if (lists[i]->val == minVal) {
                head = lists[i];
                p = head;
                lists[i] = lists[i]->next;
                break;
            }
        }
        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        
        while(lists.size() > 1)
        {
            int min = INT_MAX;
            for(auto node : lists) {
                if (node && node->val < min) {
                    min = node->val;
                }
            }
            for (int i=0; i<lists.size(); i++) {
                if (lists[i] && lists[i]->val == min) {
                    p->next = lists[i];
                    lists[i] = lists[i]->next;
                    p = p->next;
                    break;
                }
            }
            lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        }

        if (lists.size() == 1) {
            p->next = lists[0];
        }
        else if (lists.size() == 0) {
            p->next = nullptr;
        }
        return head;
    }
};