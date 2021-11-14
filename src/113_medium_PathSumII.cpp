/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
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
    void _pathSum(TreeNode * head, int targetSum, vector<int>& oneResult, vector<vector<int>>& result) {
        if (head == nullptr) return;
        
        if (head->left == nullptr && head->right == nullptr && head->val == targetSum) {
            oneResult.push_back(head->val);
            result.push_back(oneResult);
            oneResult.pop_back();
            return;
        }
        
        oneResult.push_back(head->val); 
        _pathSum(head->left, targetSum - head->val, oneResult, result);
        _pathSum(head->right, targetSum - head->val, oneResult, result);
        oneResult.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        
        vector<vector<int>> result;
        vector<int> oneResult;
        _pathSum(root, targetSum, oneResult, result);
        return result;
    }
};
