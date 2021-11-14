/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
    Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: [0,-10,5,null,-3,null,9] is also accepted
*/

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
    TreeNode * _createBST(vector<int>& nums, int beg, int end) {
        if (beg < 0 || beg >= nums.size() || end < 0 || end >= nums.size()) return nullptr;
        if (beg > end) return nullptr;
        if (beg == end) {
            TreeNode * p = new TreeNode(nums[beg]);
            return p;
        }
        
        int mid = beg + (end-beg)/2;
        TreeNode * p = new TreeNode(nums[mid]);
        p->left = _createBST(nums, beg, mid-1);
        p->right = _createBST(nums, mid+1, end);
        return p;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * head = _createBST(nums, 0, nums.size()-1);
        return head;
    }
};