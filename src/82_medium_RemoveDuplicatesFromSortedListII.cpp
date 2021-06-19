/*
    Given the head of a sorted linked list, 
    delete all nodes that have duplicate numbers, 
    leaving only distinct numbers from the original list. 
    Return the linked list sorted as well.

    Example-1:
    Input: head = [1,2,3,3,4,4,5]
    Output: [1,2,5]
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
    
    ListNode * pre = nullptr;
    ListNode * pBeg = head;
    ListNode * pEnd = pBeg->next;
    
    bool isHeadDeleted = false;
    
    /*
        用2个指针控制重复指针的范围： 
        pBeg - 第一个重复指针
        pEnd - 最后一个重复指针的下一个指针（可能为nullptr）
        
        一旦发现 pBeg->val == pEnd->val, 就找出当前所有重复指针；
        然后进行删除；
        在删除过程中，如果发现 head 被删除，标记 isHeadDeleted 为 true 
        删除结束后，调整 pre, pBeg, pEnd , 并检查 isHeadDeleted 
        如果head在刚才这一轮删除中被删了，则对head进行新的赋值，并且重置 isHeadDeleted
    */
    
    while (pEnd != nullptr) {
        if (pBeg->val == pEnd->val) {
            while (pEnd != nullptr && pBeg->val == pEnd->val) {
                pEnd = pEnd->next; 
            }

            while (pBeg != pEnd) {
                ListNode * tmp = pBeg->next;
                if (!isHeadDeleted && pBeg == head) isHeadDeleted = true;
                delete pBeg;
                pBeg = tmp;
            }
            
            if (pre != nullptr) pre->next = pBeg; 
            pBeg = pEnd;
            
            if (isHeadDeleted) {
                head = pBeg; 
                isHeadDeleted = false; 
            }
            
            if (pEnd != nullptr) pEnd = pEnd->next; 
        }
        else {  // pBeg->val != pEnd->val 
            pre = pBeg;
            pBeg = pEnd;
            pEnd = pEnd->next; 
        }
    }
    
    if (isHeadDeleted) head = pre;
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
    vector<int> vec{1, 2, 3, 3, 4, 4, 5};
    test_one_case(vec);
    
    vec = {1, 1, 1, 2, 3};
    test_one_case(vec);
    
    vec = {1, 1, 1, 1};
    test_one_case(vec);
    
    vec = {1, 1, 2};
    test_one_case(vec);
    
    return 0;
}
