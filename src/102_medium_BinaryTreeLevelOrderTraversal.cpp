/*
    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
    
    Example 1: 
        Input: root = [3,9,20,null,null,15,7]
        Output: [[3],[9,20],[15,7]]
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

void print_vec(vector<pair<int, int>>& vec) {
    for (auto& item : vec) {
        cout << "(" << item.first << ", " << item.second << "), ";
    }
    cout << endl;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    
    vector<vector<int>> result;
    
    vector<pair<int, int>> vec;
    
    pair<TreeNode *, int> tmp(root, 0);
    queue<pair<TreeNode *, int>> myqueue;
    myqueue.push(tmp);
    
    while (!myqueue.empty()) {
        tmp = myqueue.front();
        myqueue.pop();
        
        TreeNode * p = tmp.first;
        if (p) {
            int level = tmp.second;
            vec.push_back(make_pair(p->val, level));
            
            myqueue.push(make_pair(p->left, level+1));
            myqueue.push(make_pair(p->right, level+1));
        }
    }
    
    print_vec(vec);
    
    int levelSize = 0;
    for (auto& item : vec) {
        if (levelSize < item.second) levelSize = item.second;
    }
    levelSize += 1;
    
    for (int i=0; i<levelSize; i++) {
        result.push_back({});
    }
    
    for (auto& item : vec) {
        result[item.second].push_back(item.first);
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
    
    vector<vector<int>> result = levelOrder(&n1);
    
    for (auto& vec : result) {
        for (auto& i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
