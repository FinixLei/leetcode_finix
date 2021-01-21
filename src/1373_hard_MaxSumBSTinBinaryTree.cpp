/*
    Given a binary tree root, the task is to return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

    Example-1:
    Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
    Output: 20

    Example-2:
    Input: root = [4,3,null,1,2]
    Output: 2

    Example-3:
    Input: root = [-4,-2,-5]
    Output: 0

    Example-4:
    Input: root = [2,1,3]
    Output: 6

    Example-5:
    Input: root = [5,4,8,3,null,6,3]
    Output: 7
*/


#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


#define NULL_NODE -999999


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


struct ReturnSet {
    int MinKey; 
    int MaxKey;
    int SumKey;
    bool IsBST;
};


class Solution {
private:
    int MaxValue; 
    
public: 
    ReturnSet Traverse(TreeNode* root)
    {
        ReturnSet rs{0, 0, 0, false};
        
        if (root->left == NULL && root->right == NULL) {
            rs = {root->val, root->val, root->val, true};
        }
        else if (root->left != NULL && root->right == NULL) {
            ReturnSet leftRS  = Traverse(root->left);
            if (leftRS.IsBST && leftRS.MaxKey < root->val) {
                rs = {leftRS.MinKey, root->val, leftRS.SumKey + root->val, true};
            }
        }
        else if (root->left == NULL && root->right != NULL) {
            ReturnSet rightRS = Traverse(root->right);
            if (rightRS.IsBST && rightRS.MinKey > root->val) {
                rs = {root->val, rightRS.MaxKey, rightRS.SumKey + root->val, true};
            }
        }
        else {  // both left and right are not NULL 
            ReturnSet   leftRS  = Traverse(root->left);
            ReturnSet   rightRS = Traverse(root->right);

            if (leftRS.IsBST && rightRS.IsBST
                && leftRS.MaxKey < root->val && root->val < rightRS.MinKey ) {
                rs = {leftRS.MinKey, rightRS.MaxKey, 
                      root->val + leftRS.SumKey + rightRS.SumKey, true};
            }
        }
        if (rs.SumKey > this->MaxValue) this->MaxValue = rs.SumKey;
        return rs;
    }
    
    int maxSumBST(TreeNode* root) 
    {
        this->MaxValue = 0;
        ReturnSet rs = Traverse(root);
        return this->MaxValue;
    }
};


// Solution - 2: 
//    The code is shorter, as it checks "root==NULL" other than checking all the 4 cases of child nodes. 
//    But it's harder to write and understand. 

class Solution2 {
private:
    int MaxValue; 
    
public: 
    ReturnSet Traverse(TreeNode* root)
    {
        // Put INT_MAX to MinKey; Put INT_MIN to MaxKey 
        ReturnSet rs{40000, -40000, 0, true};
        
        if (root == NULL) return rs;
        
        if (root->left == NULL && root->right == NULL) {
            rs = {root->val, root->val, root->val, true};
        }

        ReturnSet   leftRS  = Traverse(root->left);
        ReturnSet   rightRS = Traverse(root->right);

        if (leftRS.IsBST && rightRS.IsBST
            && leftRS.MaxKey < root->val && root->val < rightRS.MinKey ) {
            rs.IsBST = true;
            rs.MinKey = min(leftRS.MinKey, root->val);
            rs.MaxKey = max(rightRS.MaxKey, root->val);
            rs.SumKey = root->val + leftRS.SumKey + rightRS.SumKey;
        }
        else {
            rs = {0, 0, 0, false};
        }
        
        if (rs.SumKey > this->MaxValue) this->MaxValue = rs.SumKey;
        return rs;
    }
    
    int maxSumBST(TreeNode* root) 
    {
        this->MaxValue = 0;
        ReturnSet rs = Traverse(root);
        return this->MaxValue;
    }
};


void PrintTreeInLevelOrder(TreeNode* root)
{
    if (root == NULL) return;
    
    deque<TreeNode *> q;
    q.push_back(root);
    
    while (q.size() > 0) {
        TreeNode* tmp = q.front();
        if (tmp != NULL) {
            cout << tmp->val << " ";
            q.push_back(tmp->left);
            q.push_back(tmp->right);
        }
        else {
            cout << "NULL ";
        }
        q.pop_front();
    }
    cout << endl;
}

// Solution-2 for Constructing A Tree 
//     This way works for the tree represented in full-level-order vector. 
//     But this way does not work for this Problem's input, 
//     as which is not a full-level-order vector. 
/*
TreeNode* ConstructTree(const vector<int>& vec)
{
    deque<int> q(vec.begin(), vec.end());
    vector<TreeNode *> nodePtrVec;
    
    while (q.size() > 0) {
        TreeNode * tmp = NULL;
        if (q.front() != NULL_NODE) tmp = new TreeNode(q.front());
        nodePtrVec.push_back(tmp);
        q.pop_front();
    }
    
    int startPos = (nodePtrVec.size() - 2 ) / 2;
    if (startPos < 0) startPos = 0;
    
    while (startPos >= 0) {
        if (nodePtrVec[startPos] == NULL) {
            startPos --;
            continue;
        }
        
        int left = startPos * 2 + 1;
        int right = startPos * 2 + 2;
        nodePtrVec[startPos]->left = nodePtrVec[left];
        if (right < nodePtrVec.size()) {
            nodePtrVec[startPos]->right = nodePtrVec[right];
        }
        startPos --;
    }
    
    return nodePtrVec[0];
}
*/

// Use 2 cursors to construct the tree. 
// - One cursor points to current parent node; 
// - The other cursor points to current child node (left or right) 
// Use 2 vectors
// - One is for values;
// - The other is for storing the pointers. 
// 
TreeNode* ConstructTree(const vector<int>& vec)
{
    int size = vec.size();
    
    if (size == 0) return NULL;
    
    if (vec[0] == NULL_NODE) {
        return NULL;
    }
    
    vector<TreeNode *> ptrVec;
    ptrVec.reserve(size);
    
    int curNodePos  = 0;
    int curValuePos = 1;
    TreeNode * root = new TreeNode(vec[0]);
    ptrVec.push_back(root);
    TreeNode * h = ptrVec[0];
    
    while (curValuePos < size) {
        if (vec[curValuePos] == NULL_NODE) {
            h->left = NULL;
        }
        else {
            h->left = new TreeNode(vec[curValuePos]);
        }
        ptrVec.push_back(h->left);
        
        curValuePos ++;
        if (curValuePos >= size) break;
        
        if (vec[curValuePos] == NULL_NODE) {
            h->right = NULL;
        }
        else {
            h->right = new TreeNode(vec[curValuePos]);
        }
        ptrVec.push_back(h->right);
        
        curValuePos ++;
        if (curValuePos >= size) break;
        
        curNodePos ++;
        while (vec[curNodePos] == NULL_NODE && curNodePos < size) {
            curNodePos ++;
        }
        if (curNodePos >= size) break;
        h = ptrVec[curNodePos];
    }
    
    return root;
}


int main()
{
    {
        vector<int> inputArray {5, 4, 8, 3, NULL_NODE, 6, 3};
        TreeNode * root = ConstructTree(inputArray);
        PrintTreeInLevelOrder(root);
        Solution s1; 
        int maxValue = s1.maxSumBST(root);
        cout << "Max Sum is " << maxValue << endl;
    }

    {
        vector<int> inputArray {1, -3, 5, NULL_NODE, -2, NULL_NODE, 6};
        TreeNode * root = ConstructTree(inputArray);
        PrintTreeInLevelOrder(root);
        Solution s1; 
        int maxValue = s1.maxSumBST(root);
        cout << "Max Sum is " << maxValue << endl;  // 11
    }
    
    {
        // TreeNode * root = new TreeNode(8);
        // root->left = new TreeNode(9);
        // root->right = new TreeNode(8);
        // root->left->left = NULL;
        // root->left->right = new TreeNode(9);
        // root->right->left = NULL;
        // root->right->right = new TreeNode(1);
        // root->right->right->left = new TreeNode(-3);
        // root->right->right->right = new TreeNode(5);
        // root->right->right->left->left = NULL;
        // root->right->right->left->right = new TreeNode(-2);
        // root->right->right->right->left = NULL;
        // root->right->right->right->right = new TreeNode(6);
        
        vector<int> inputArray {8, 9, 8, NULL_NODE, 9, NULL_NODE, 1, NULL_NODE, NULL_NODE, -3, 5, NULL_NODE, -2, NULL_NODE, 6}; 
        TreeNode * root = ConstructTree(inputArray);
        PrintTreeInLevelOrder(root);
        Solution s1; 
        int maxValue = s1.maxSumBST(root);
        cout << "Max Sum is " << maxValue << endl;  // 11
    }
    
    {
        // TreeNode * root = new TreeNode(4);
        // root->left = new TreeNode(3);
        // root->right = new TreeNode(8);
        // root->left->left = new TreeNode(3);
        // root->left->left->left  = new TreeNode(1);
        // root->left->left->right = new TreeNode(4);
        // root->left->left->right->right = new TreeNode(5);
        // root->right->right = new TreeNode(7);
        // root->right->right->right = new TreeNode(6);
        // root->right->right->right->left = new TreeNode(10);
        
        vector<int> inputArray {4, 3, 8, 3, NULL_NODE, NULL_NODE, 7, 1, 4, NULL_NODE, 6, NULL_NODE, NULL_NODE, NULL_NODE, 5, 10}; 
        TreeNode * root = ConstructTree(inputArray);
        PrintTreeInLevelOrder(root);
        Solution s1; 
        int maxValue = s1.maxSumBST(root);
        cout << "Max Sum is " << maxValue << endl;  // 13
    }
    
    return 0;
}
