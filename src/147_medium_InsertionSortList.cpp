/*
    Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
    The steps of the insertion sort algorithm:
    Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
    At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
    It repeats until no input elements remain.
    The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

    Example 1:
        Input: head = [4,2,1,3]
        Output: [1,2,3,4]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode * insertToList(ListNode * currHead, ListNode * node) {
        if (currHead == node) return currHead;
        
        if (node->val <= currHead->val) {
            node->next = currHead;
            return node;
        }

        ListNode * p1 = currHead;
        ListNode * p2 = currHead->next;

        while(p2 != nullptr) {
            if (node->val <= p2->val) { // node->val must be greater than p1->val
                p1->next = node;
                node->next = p2;
                return currHead;
            }
            p1 = p2;
            p2 = p2->next;
        }
        if (node->val > p1->val) {
            p1->next = node;
            node->next = nullptr;
        }
        return currHead;
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode * newHead = head;
        while (head != nullptr) {
            ListNode * tmpNode = head;
            head = head->next;
            tmpNode->next = nullptr;
            newHead = insertToList(newHead, tmpNode);
        }
        return newHead;
    }
};