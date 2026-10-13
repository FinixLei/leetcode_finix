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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res = {};
        if (root == nullptr) return res;

        vector<TreeNode *> v1 = {root};
        vector<TreeNode *> v2 = {};

        while (!v1.empty()) {
            long s = 0;
            for(TreeNode *p : v1) {
                s += p->val;
                if (p->left) v2.push_back(p->left);
                if (p->right) v2.push_back(p->right);
            }
            res.push_back((double)s / v1.size());
            v1.clear();
            swap(v1, v2);
        }
        return res;
    }
};
