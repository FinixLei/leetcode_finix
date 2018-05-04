/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/


#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    for (auto it=lists.begin(); it!=lists.end();) {
        if ((*it) == NULL)
            lists.erase(it);
        else
            ++it;
    }
    
    ListNode* head = NULL;
    ListNode* p = NULL;
    ListNode* tmp_node = NULL; 
    
    while(lists.size() > 0)
    {
        int min = 9999;
        for(auto node : lists) {
            if (node != NULL && node->val < min) {
                min = node->val;
                tmp_node = node;
            }
        }
        
        for (auto it=lists.begin(); it!=lists.end(); ++it) {
            if ((*it)->val == tmp_node->val) {
                lists.erase(it);
                break;
            }
        }
        
        if (tmp_node->next != NULL) {
            lists.push_back(tmp_node->next);
        }
        
        tmp_node->next = NULL;
        if (head == NULL) {
            head = tmp_node;
            p = head;
        }
        else {
            p -> next = tmp_node;
            p = p->next;
        }
    }
    
    return head;
}

int main(int argc, char ** argv)
{
    ListNode a1(1), a2(4), a3(5);
    ListNode b1(1), b2(3), b3(4);
    ListNode c1(2), c2(6);
    
    a1.next = &a2; a2.next = &a3;
    b1.next = &b2; b2.next = &b3;
    c1.next = &c2;
    
    vector<ListNode*> lists;
    lists.push_back(NULL);
    lists.push_back(&a1);
    lists.push_back(&b1);
    lists.push_back(&c1);
    
    ListNode* h = mergeKLists(lists);
    ListNode* h2 = h;
    while (h2 != NULL && h2->next != NULL) {
        cout << h2->val << "->";
        h2 = h2->next;
    }
    cout << h2->val << endl;
    
    return 0;
}