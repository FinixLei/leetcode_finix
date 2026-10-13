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
    int k = 0;
    int count = 0;
    int bSet = false;
    int res = 0;

    void midLoop(TreeNode *p) {
        if (bSet) return;
        if (p == nullptr) return;

        midLoop(p->left);
        count ++;
        if (count == k) {
            res = p->val;
            bSet = true;
        }
        midLoop(p->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (k == 0) return 0;
        this->k = k;
        midLoop(root);
        return res;
    }
};
