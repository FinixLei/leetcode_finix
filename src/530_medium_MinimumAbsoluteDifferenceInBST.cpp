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
private:
    vector<int> vec;

private:
    void midLoopTree(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) midLoopTree(root->left);
        vec.push_back(root->val);
        if (root->right) midLoopTree(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return -1;
        midLoopTree(root);

        int record = INT_MAX;
        for (int i=0; i<vec.size()-1; i++) {
            int diff = vec[i+1] - vec[i];
            if (diff == 0) return 0;
            if (diff < record) record = diff;
        }
        return record;
    }
}; 

