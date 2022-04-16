/*
    Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
    and postorder is the postorder traversal of the same tree, construct and return the binary tree.
    
    Example-1:
    Input: postorder = [9,3,15,20,7], inorder = [9,15,7,20,3]
    Output: [3,9,20,null,null,15,7]
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_vec(vector<int>& vec) {
    for (auto i : vec) cout << i << " ";
    cout << endl;
}

TreeNode * _buildTree(const vector<int>& inorder, int inorderStart, int inorderEnd,
                      const vector<int>& postorder, int postorderStart,int postorderEnd)
{
    const int size = inorderEnd - inorderStart + 1;
    
    if (size <= 0) return nullptr;
    
    TreeNode * root = new TreeNode(postorder[postorderEnd]);
    
    int rootPosInOrder = -1;
    for (int i=inorderStart; i<=inorderEnd; i++) {
        if (inorder[i] == root->val) {
            rootPosInOrder = i;
            break;
        }
    }
    
    int leftInorderStart = inorderStart;
    int leftInorderEnd = rootPosInOrder - 1;
    int rightInorderStart = rootPosInOrder + 1;
    int rightInorderEnd = inorderEnd;
    
    int leftTreeSize = leftInorderEnd - leftInorderStart + 1;
    
    int leftPostorderStart = postorderStart;
    int leftPostorderEnd = leftPostorderStart + leftTreeSize - 1;
    int rightPostorderStart = leftPostorderEnd + 1;
    int rightPostorderEnd = postorderEnd - 1;
    
    root->left = _buildTree(inorder, leftInorderStart, leftInorderEnd, 
                           postorder, leftPostorderStart, leftPostorderEnd);
    root->right = _buildTree(inorder, rightInorderStart, rightInorderEnd, 
                            postorder, rightPostorderStart, rightPostorderEnd);
    
    return root;
}
    
TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder)
{
    return _buildTree(inorder, 0, inorder.size()-1, 
                      postorder, 0, postorder.size()-1); 
}    

int main()
{
    vector<int> postorder = {1, 2};
    vector<int> inorder = {2, 1};
    
    TreeNode * root = buildTree(inorder, postorder);
    
    return 0;
}
