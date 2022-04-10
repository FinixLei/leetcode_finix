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
    int _preorder(TreeNode * root)
    {
        if (root == nullptr) return 0;
        return max(_preorder(root->left), _preorder(root->right)) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return _preorder(root);
    }
    
    int maxDepth_way2(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int level = 1;
        queue<pair<TreeNode *, int>> myqueue;
        pair<TreeNode *, int> tmp = {root, 1};
        
        myqueue.push(tmp);
        while(!myqueue.empty()) {
            tmp = myqueue.front();
            myqueue.pop();
            
            if (tmp.first != nullptr) {
                level = tmp.second;
                level += 1;
                
                myqueue.push(make_pair(tmp.first->left, level));
                myqueue.push(make_pair(tmp.first->right, level));
            }
        }
        
        return level-1;
    }
};