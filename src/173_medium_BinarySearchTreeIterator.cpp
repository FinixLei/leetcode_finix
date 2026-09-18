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
class BSTIterator {
private:
    vector<int> _vec = {};
    int _index = -1;

private:
    void _loop_tree(TreeNode * root) {
        if (root == nullptr) return;
        _loop_tree(root->left);
        _vec.push_back(root->val);
        _loop_tree(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        if (root == nullptr) return;
        _loop_tree(root);
        _index = 0;
    }
    
    int next() {
        if (hasNext()) {
            return _vec[_index++];
        }
        throw std::runtime_error("No such element");
    }
    
    bool hasNext() {
        return _index < _vec.size();
    }
};

