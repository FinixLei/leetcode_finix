/*
    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    Note: A leaf is a node with no children.

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
    void preorder(TreeNode * root, int currentLayer, int & minLayers) 
    {
        int layer = currentLayer + 1;
        
        if (root->left == nullptr && root->right == nullptr) {
            if (layer < minLayers) minLayers = layer; 
            return;
        }
        
        if (root->left != nullptr) preorder(root->left, layer, minLayers);
        if (root->right != nullptr) preorder(root->right, layer, minLayers);
    }
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int minLayers = 9999;
        preorder(root, 0, minLayers);
        return minLayers;
    }
};