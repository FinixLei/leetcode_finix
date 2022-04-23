/*
    Given a binary tree, determine if it is height-balanced.
    For this problem, a height-balanced binary tree is defined as:
    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: true
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int getLayers(TreeNode * root) {
        if (root == nullptr) return 0;
        
        int layer1 = getLayers(root->left);
        if (layer1 < 0) return -1;
        
        int layer2 = getLayers(root->right);
        if (layer2 < 0) return -1;
        
        int big = max(layer1, layer2);
        int small = min(layer1, layer2);
        if (big - small <= 1) return big+1;
        return -1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (getLayers(root) < 0) return false;
        return true;
    }
};
