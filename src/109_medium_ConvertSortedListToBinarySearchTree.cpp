/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * _createBST(ListNode * head, ListNode * tail) {
        if (head == nullptr) return nullptr;
        if (head == tail || head->next == nullptr) {
            TreeNode * p = new TreeNode(head->val);
            return p;
        }
        
        ListNode * preP1 = nullptr;
        ListNode * p1 = head;
        ListNode * p2 = p1->next; 
        while (p2 != tail) {
            preP1 = p1;
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == tail) break;
            p2 = p2->next;
        }
        
        TreeNode * k = new TreeNode(p1->val);
        
        if(preP1 == nullptr) {
            k->left = nullptr;
        }
        else {
            k->left = _createBST(head, preP1);
        }
        
        k->right = _createBST(p1->next, tail);
        return k;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) {
            TreeNode * p = new TreeNode(head->val);
            return p;
        }
            
        TreeNode * root = _createBST(head, nullptr);
        return root;
    }
};