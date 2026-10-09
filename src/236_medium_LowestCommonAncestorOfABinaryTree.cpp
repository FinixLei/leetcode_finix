/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool getNodePath(TreeNode* root, TreeNode* p, vector<TreeNode*>& nodeList) {
        if (root == p) {
            return true;
        }
        if (root->left) {
            bool leftResult = getNodePath(root->left, p, nodeList);
            if (leftResult) {
                nodeList.push_back(root->left);
                return true;
            }
        }
        if (root->right) {
            bool rightResult = getNodePath(root->right, p, nodeList);
            if (rightResult) {
                nodeList.push_back(root->right);
                return true;
            }
        }
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pVec = {};
        vector<TreeNode*> qVec = {};
        getNodePath(root, p, pVec);
        getNodePath(root, q, qVec);

        int pSize = pVec.size();
        int qSize = qVec.size();

        if (pSize == 0 || qSize == 0) return root;  // optimization

        int i=0, j=pSize-1;
        while (i < j) {
            swap(pVec[i++], pVec[j--]);
        }

        i = 0;
        j = qSize-1;
        while (i < j) {
            swap(qVec[i++], qVec[j--]);
        }

        if (pVec[0] != qVec[0]) return root;  // optimization

        int minSize = min(pSize, qSize);
        TreeNode* lastSame = nullptr;

        for (i=0; i<minSize; i++) {
            if (pVec[i] == qVec[i]) {
                lastSame = pVec[i];
            }
            else {
                break;
            }
        }

        return lastSame;
    }
};