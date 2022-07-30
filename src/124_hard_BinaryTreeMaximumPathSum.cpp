/*
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
    A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.

    Example 1:
        Input: root = [1,2,3]
        Output: 6
    Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

    Example 2:
        Input: root = [-10,9,20,null,null,15,7]
        Output: 42
    Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/

#include <climits>
#include <unordered_map>

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
int helper(TreeNode * root, int & maxValue) {
    if (root == nullptr) {
        return 0; 
    }

    if (root->left == nullptr && root->right == nullptr) {
        if (root->val > maxValue) maxValue = root->val;
        return root->val;
    }

    int leftValue = helper(root->left, maxValue);
    int rightValue = helper(root->right, maxValue);

    int rv = max(leftValue, rightValue) + root->val;
    rv = max(rv, root->val);

    int v1 = max(root->val, root->val + leftValue + rightValue);
    int v2 = max(root->val + leftValue, root->val + rightValue);
    int maxPathValue = max(v1, v2);
    if (maxPathValue > maxValue) maxValue = maxPathValue;
    
    return rv;
}
    
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        helper(root, maxValue);
        return maxValue; 
    }
};