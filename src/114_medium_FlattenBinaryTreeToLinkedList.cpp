/*
    Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.
     

    Example 1:
    Input: root = [1,2,5,3,4,null,6]
    Output: [1,null,2,null,3,null,4,null,5,null,6]
*/

#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrderPrint(TreeNode * root) 
{
    if (root == nullptr) return;
    cout << root->val << " ";
    
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}


void printRightPath(TreeNode * root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    
    TreeNode * tmp = root->right;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->right;
    }
    cout << endl;
}

// Given a tree, flattern it and return the last node 
TreeNode * helper(TreeNode * root)
{
    if (root == nullptr) return root;
    if (!root->left && !root->right) return root;
    
    TreeNode * begOfLeft = root->left; 
    TreeNode * endOfLeft = helper(root->left);
    
    TreeNode * begOfRight = root->right;
    TreeNode * endOfRight = helper(root->right);
    
    TreeNode * lastNode = nullptr;
    
    if (root->left != nullptr && root->right != nullptr) {
        root->left = nullptr;
        root->right = begOfLeft; 
        endOfLeft->right = begOfRight;
        lastNode = endOfRight;
    }
    else if (root->left != nullptr && root->right==nullptr) {
        root->left = nullptr;
        root->right = begOfLeft;
        lastNode = endOfLeft;
    }
    else if (root->left == nullptr && root->right != nullptr) {
        lastNode = endOfRight;
    }
    else { // both left and right are nullptr, but never get here
        lastNode = root;
    }
    
    return lastNode;
}

void flatten(TreeNode* root) 
{
    helper(root);
}

int main()
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.left  = &n2;
    n1.right = &n5;
    n2.left  = &n3; 
    n2.right = &n4; 
    n5.right = &n6; 
    
    preOrderPrint(&n1);
    cout << endl;
    
    flatten(&n1);
    printRightPath(&n1);
    
    preOrderPrint(&n1);
    cout << endl;
    
    return 0;
}
