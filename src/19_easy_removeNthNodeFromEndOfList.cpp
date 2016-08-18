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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> vec;
        ListNode* tmp = head;
        while(tmp != NULL) {
            vec.push_back(tmp);
            tmp = tmp->next; 
        }
        int size = vec.size();
        int target = size - n;
        
        if (target == 0) {
            tmp = head->next;
            delete head; 
            return tmp;
        }
        
        vec[target-1]->next = vec[target]->next;
        delete vec[target];
        return head;
    }
};
