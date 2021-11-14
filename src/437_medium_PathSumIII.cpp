/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Example-1: 
    Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    Output: 3
    Explanation: The paths that sum to 8 are shown.

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
    int cnt = 0;
    
    void helper(TreeNode *root, int targetSum) {
        if (root == nullptr) return;
        if (targetSum == root->val) cnt++;
        
        helper(root->left, targetSum - root->val);
        helper(root->right, targetSum - root->val);
    }
    
    void EndFunc(TreeNode* root, int targetSum) {
        if (root == nullptr) return;
        if ((root->left == nullptr) && (root->right == nullptr) && (root->val != targetSum)) return;

        helper(root, targetSum);
        EndFunc(root->left, targetSum);
        EndFunc(root->right, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        EndFunc(root, targetSum);
        return cnt;
    }
};