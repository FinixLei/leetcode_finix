/*
    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
    
    Example-1:
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode * _buildTree(vector<int>& preorder, int poStart, int poEnd, 
                      vector<int>& inorder,  int ioStart, int ioEnd, 
                      unordered_map<int, int>& inorderHashMap) 
{
    const int size = ioEnd - ioStart + 1;
    if (size <= 0) return nullptr;
    
    TreeNode * root = new TreeNode(preorder[poStart]);
    
    int rootPosInOrder = inorderHashMap[root->val];
    
    int leftTreeInorderStart = ioStart;
    int leftTreeInorderEnd = rootPosInOrder - 1;
    int rightTreeInorderStart = rootPosInOrder + 1;
    int rightTreeInorderEnd = ioEnd;
    
    int leftTreeSize = leftTreeInorderEnd - leftTreeInorderStart + 1;
    
    int leftTreePreorderStart = poStart + 1; 
    int leftTreePreorderEnd = poStart + leftTreeSize; 
    int rightTreePreorderStart = leftTreePreorderEnd + 1;
    int rightTreePreorderEnd = poEnd;
    
    root->left  = _buildTree(preorder, leftTreePreorderStart, leftTreePreorderEnd, 
                             inorder,  leftTreeInorderStart,  leftTreeInorderEnd, inorderHashMap);
    root->right = _buildTree(preorder, rightTreePreorderStart, rightTreePreorderEnd, 
                             inorder,  rightTreeInorderStart,  rightTreeInorderEnd, inorderHashMap);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderHashMap;
    for (int i=0; i<inorder.size(); i++) {
        inorderHashMap[inorder[i]] = i;
    }
    
    return _buildTree(preorder, 0, preorder.size()-1, 
                      inorder,  0, inorder.size()-1,
                      inorderHashMap);
}

int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder  = {9,3,15,20,7};
    
    TreeNode * root = buildTree(preorder, inorder);
    
    return 0;
}
