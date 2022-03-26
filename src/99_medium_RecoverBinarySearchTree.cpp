/*
    You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example 1:
    Input: root = [1,3,null,null,2]
    Output: [3,1,null,null,2]
    Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
    
Example 2:
    Input: root = [3,1,4,null,null,2]
    Output: [2,1,4,null,null,3]
    Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

Constraints:
    The number of nodes in the tree is in the range [2, 1000].
    -2^(31) <= Node.val <= 2^(31) - 1
 
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void fetchAllNodes(TreeNode * root, vector<pair<int, TreeNode *>> & vec)
{
    if (root == nullptr) return;
    
    if (root->left) fetchAllNodes(root->left, vec);
    vec.push_back({root->val, root});
    if (root->right) fetchAllNodes(root->right, vec);
}
 
void recoverTree(TreeNode* root) 
{
    vector<pair<int, TreeNode *>> vec;
    fetchAllNodes(root, vec);
    
    TreeNode * t1 = nullptr;
    TreeNode * t2 = nullptr;
    
    vector<int> oldVec;
    for (auto& item : vec) {
        oldVec.push_back(item.first);
    }
    
    vector<int> newVec = oldVec;
    sort(newVec.begin(), newVec.end());
    
    int n1=-1, n2=-1;
    for (int i=0; i<oldVec.size(); i++) {
        if (oldVec[i] != newVec[i]) {
            if (n1 < 0) {
                n1 = i;
            }
            else {
                n2 = i;
                break;
            }
        }
    }
    
    if (n1 >= 0 && n2 >= 0) {
        swap(vec[n1].second->val, vec[n2].second->val);
    }
}
