struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxDepth(TreeNode *head, int& global_max) {
    if (head == NULL) return 0;
    
    int d1 = maxDepth(head->left, global_max);
    int d2 = maxDepth(head->right, global_max);
    
    global_max = max(global_max, d1+d2);
    
    return max(d1, d2) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    int global_max = 0;
    
    int d1 = maxDepth(root->left, global_max);
    int d2 = maxDepth(root->right, global_max);
    global_max = max(global_max, d1+d2);
    
    return global_max;
}

