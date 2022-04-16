/*
    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
    
    Example-1:
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) return nullptr;
    
    TreeNode * root = new TreeNode(preorder[0]);
    
    int rootPosInOrder = -1;
    for (int i=0; i<inorder.size(); i++) {
        if (inorder[i] == preorder[0]) {
            rootPosInOrder = i;
            break;
        }
    }
    
    vector<int> leftInOrder;
    vector<int> rightInOrder;
    set<int> leftTreeSet;
    
    for (int i=0; i<rootPosInOrder; i++) {
        leftInOrder.push_back(inorder[i]);
        leftTreeSet.insert(inorder[i]);
    }
    for (int i=rootPosInOrder+1; i<inorder.size(); i++) {
        rightInOrder.push_back(inorder[i]);
    }
    
    vector<int> leftPreOrder;
    vector<int> rightPreOrder;
    
    int rightTreeStartInPreOrder = preorder.size();
    for (int i=1; i<preorder.size(); i++) {
        if (leftTreeSet.find(preorder[i]) == leftTreeSet.end()) {
            rightTreeStartInPreOrder = i;
            break;
        }
    }
    
    for (int i=1; i<rightTreeStartInPreOrder; i++) {
        leftPreOrder.push_back(preorder[i]);
    }
    for (int i=rightTreeStartInPreOrder; i< preorder.size(); i++) {
        rightPreOrder.push_back(preorder[i]);
    }
    
    // cout << "Left Tree Size: " << leftTreeSet.size() << endl;
    // cout << "Left PreOrder: \n";
    // print_vec(leftPreOrder);
    // cout << "Right PreOrder: \n";
    // print_vec(rightPreOrder);
    // 
    // cout << "Left InOrder: \n";
    // print_vec(leftInOrder);
    // cout << "Right InOrder: \n";
    // print_vec(rightInOrder);
    // cout << "------------------------" << endl;
    
    root->left = buildTree(leftPreOrder, leftInOrder);
    root->right = buildTree(rightPreOrder, rightInOrder);
    
    return root;
}

int main()
{
    vector<int> preorder = {1, 2};
    vector<int> inorder = {2, 1};
    
    TreeNode * root = buildTree(preorder, inorder);
    
    return 0;
}
