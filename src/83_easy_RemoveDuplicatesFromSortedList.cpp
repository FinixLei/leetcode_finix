/*
    Given the head of a sorted linked list, 
    delete all duplicates such that each element appears only once. 
    Return the linked list sorted as well.

    Example-1:
    Input: head = [1,1,5]
    Output: [1,5]
*/


#include <vector>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode * createList(const vector<int>& vec)
{
    if (vec.size() == 0) return nullptr;
    
    ListNode * head = nullptr;
    ListNode * pCurr = nullptr;
    
    for(auto val : vec) {
        if (head == nullptr) {
            head = new ListNode(val);
            pCurr = head;
        }
        else {
            ListNode * tmp = new ListNode(val);
            pCurr->next = tmp; 
            pCurr = pCurr->next;
        }
    }
    
    return head;
}

void printList(ListNode * h)
{
    while (h != nullptr) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
}

void deleteList(ListNode * head)
{
    while (head) {
        ListNode * tmp = head->next; 
        delete head;
        head = tmp;
    }
}

ListNode* deleteDuplicates(ListNode* head) 
{
    if (head == nullptr) return head;
    
    ListNode * pNode = head; 
    ListNode * pNext = head->next; 
    
    while (pNext != nullptr) {
        if (pNode->val == pNext->val) {
            ListNode * tmp = pNext->next; 
            delete pNext; 
            pNext = tmp; 
            pNode->next = pNext; 
        }
        else {
            pNode = pNext; 
            pNext = pNext->next;
        }
    }

    return head;
}

void test_one_case(vector<int>& vec)
{
    ListNode * head = createList(vec);
    printList(head);
    head = deleteDuplicates(head);
    cout << "output: ";
    printList(head);
    deleteList(head);
}

int main()
{
    vector<int> vec{1, 1, 2};
    test_one_case(vec);
    
    vec = {1, 1, 2, 3, 5};
    test_one_case(vec);
    
    vec = {1, 1, 1, 1};
    test_one_case(vec);
    
    vec = {1, 1, 2, 2, 3};
    test_one_case(vec);
    
    return 0;
}
