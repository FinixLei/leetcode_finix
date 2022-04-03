/*
    Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    You should preserve the original relative order of the nodes in each of the two partitions.

    Example 1:
        Input: head = [1,4,3,2,5,2], x = 3
        Output: [1,2,2,4,3,5]
*/

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void print_list(ListNode * head)
{
    if (head == nullptr) return;
    do {
        cout << head->val << " ";
        head = head->next;
    } while(head);
    cout << endl;
}

// 将比x小的节点和大于等于x的节点分别放进2个链表，然后再连接起来
ListNode* partition(ListNode* head, int x) 
{
    if (head == nullptr) return nullptr;
    
    ListNode tmpLeftNode(-1);
    ListNode tmpRightNode(-1);
    
    ListNode * pLeft = &tmpLeftNode;
    ListNode * pRight = &tmpRightNode;
    ListNode * p = head;
    ListNode * tmpNext = nullptr;
    
    while (p != nullptr) {
        tmpNext = p->next;
        
        if (p->val < x) {
            pLeft->next = p;
            pLeft = pLeft->next;
            pLeft->next = nullptr;
        }
        else {  // p->val >= x
            pRight->next = p;
            pRight = pRight->next;
            pRight->next = nullptr;
        }
        p = tmpNext;
    }
    if (tmpLeftNode.next) {
        pLeft->next = tmpRightNode.next;
        return tmpLeftNode.next;
    }
    
    return tmpRightNode.next;
}


int main()
{
    ListNode n1(1), n2(4), n3(3), n4(2), n5(5), n6(2);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    
    print_list(&n1);
    ListNode * pn = partition(&n1, 3);
    print_list(pn);
    
    return 0;
}
