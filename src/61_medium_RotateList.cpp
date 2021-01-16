/*
Given the head of a linked list, rotate the list to the right by k places.

Example-1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example-2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

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


ListNode* rotateRight(ListNode* head, int k) 
{
    if (head == NULL) return NULL;
    if (k == 0) return head;
    
    int n = 0;
    ListNode* h = head;
    ListNode* last = NULL;
    
    while (h != NULL) {
        n++;
        last = h;
        h = h->next;
    }
    
    if (k % n == 0) return head;
    
    int count = n - k % n;
    ListNode* mid = head; 
    
    while (count > 1) {
        mid = mid->next;
        count --;
    }
    
    h = mid->next;
    mid->next = NULL;
    last->next = head;
    
    return h;
}

