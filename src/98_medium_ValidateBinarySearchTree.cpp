/*
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:
    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.
*/


#include <queue>
#include <vector>
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

void fetchAllNodes(TreeNode * root, vector<int> & vec)
{
    if (root == nullptr) return;
    
    if (root->left) fetchAllNodes(root->left, vec);
    vec.push_back(root->val);
    if (root->right) fetchAllNodes(root->right, vec);
}
 
bool isValidBST(TreeNode* root) 
{
    vector<int> vec;
    
    fetchAllNodes(root, vec);
    
    for (int i=0; i<vec.size()-1; i++) {
        if (vec[i] >= vec[i+1]) return false;
    }
    return true;
}

int main() 
{
    
    return 0;
}