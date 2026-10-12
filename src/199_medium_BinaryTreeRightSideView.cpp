// way-1. 

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
struct NodeInfo {
    TreeNode * tnp;
    int level;
    NodeInfo(TreeNode *p, int lev) : tnp(p), level(lev) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec = {};
        if (root == nullptr) return vec;

        queue<NodeInfo> q;
        q.push(NodeInfo(root, 1));
        
        while(!q.empty()) {
            NodeInfo n = q.front();
            q.pop();
            if (q.empty()) {
                vec.push_back(n.tnp->val);
            }
            else {
                NodeInfo tmp = q.front();
                if (n.level < tmp.level) vec.push_back(n.tnp->val);
            }
            if (n.tnp->left) q.push(NodeInfo(n.tnp->left, n.level + 1));
            if (n.tnp->right) q.push(NodeInfo(n.tnp->right, n.level + 1));
        }
        return vec;
    }
};

// Way-2

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec = {};
        if (root == nullptr) return vec;

        vector<TreeNode *> vt1 = {root};
        vector<TreeNode *> vt2 = {};

        while (!vt1.empty() || !vt2.empty()) {
            if (!vt1.empty()) {
                vec.push_back(vt1.back()->val);
                vt2.clear();
                for (TreeNode* tp : vt1) {
                    if (tp->left) vt2.push_back(tp->left);
                    if (tp->right) vt2.push_back(tp->right);
                }
                vt1.clear();
            } 
            else {  // !vt2.empty()
                std::swap(vt1, vt2);
            }
        }
        return vec;
    }
};
