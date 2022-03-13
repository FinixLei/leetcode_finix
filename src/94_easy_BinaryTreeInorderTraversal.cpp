/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
    Input: root = [1,null,2,3]
    Output: [1,3,2]
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

class Solution {
public:
    void _helper(TreeNode * root, vector<int>& result) {
        if (root == nullptr) return;
        
        _helper(root->left, result);
        result.push_back(root->val);
        _helper(root->right, result);
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if (root == nullptr) return result;
        _helper(root, result);
        
        return result;
    }
};
