/*
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Example 1:
    Input: root = [1,2,2,3,4,4,3]
    Output: true
    
    Example 2:
    Input: root = [1,2,2,null,3,null,3]
    Output: false
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
    bool _isSame(TreeNode * r1, TreeNode * r2) {
        if (r1 == nullptr && r2 == nullptr) return true;
        if (r1 && r2 == nullptr) return false;
        if (r1 == nullptr && r2) return false;
        
        if (r1->val != r2->val) return false;
        
        return _isSame(r1->left, r2->right) && _isSame(r1->right, r2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return _isSame(root->left, root->right);
    }
};
