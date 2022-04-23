/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[15,7],[9,20],[3]]
*/

#include <vector>
#include <queue>
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

void print_2Dvec(vector<vector<int>>& vec)
{
    for (auto& v : vec) {
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
}

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
    vector<vector<int>> result;
    
    if (root == nullptr) return result;
    
    int maxLevel = 0;
    queue<pair<int, TreeNode *>> myqueue;
    myqueue.push(make_pair(0, root));

    vector<pair<int, TreeNode *>> tmpResult;
    
    while (!myqueue.empty()) {
        pair<int, TreeNode *> tmpItem = myqueue.front();
        myqueue.pop();
        
        int level = tmpItem.first;
        if (maxLevel < level) maxLevel = level;
        
        if (tmpItem.second != nullptr) {
            tmpResult.push_back(tmpItem);
            
            if (tmpItem.second->left != nullptr) {
                myqueue.push(make_pair(level+1, tmpItem.second->left));
            }
            if (tmpItem.second->right != nullptr) {
                myqueue.push(make_pair(level+1, tmpItem.second->right));
            }
        }
    }
    
    for (int i=0; i<=maxLevel; i++) {
        result.push_back({});
    }
    
    for (int i=0; i<tmpResult.size(); i++) {
        int level = maxLevel - tmpResult[i].first;
        result[level].push_back(tmpResult[i].second->val);
    }

    return result;
}


int main()
{
    TreeNode n1(3), n2(9), n3(20), n4(15), n5(7);
    n1.left  = &n2;
    n1.right = &n3;
    n3.left  = &n4;
    n3.right = &n5;
    
    vector<vector<int>> result = levelOrderBottom(&n1);
    print_2Dvec(result);
    
    return 0;
}
