/*
    Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
    (i.e., from left to right, then right to left for the next level and alternate between).
    
    Example 1: 
        Input: root = [3,9,20,null,null,15,7]
        Output: [[3],[20,9],[15,7]]
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
            
            level += 1;
            myqueue.push(make_pair(p->left, level));
            myqueue.push(make_pair(p->right, level));
        }
    }
    
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
    
    for (int i=0; i<result.size(); i++) {
        if (i % 2) {
            for (int beg=0, end=result[i].size()-1; beg<end; beg++, end--) {
                swap(result[i][beg], result[i][end]);
            }
        }
    }
    
    return result;
}

int main()
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left  = &n2;
    n1.right = &n3;
    n2.left  = &n4;
    n3.right = &n5;
    
    vector<vector<int>> result = zigzagLevelOrder(&n1);
    
    for (auto& vec : result) {
        for (auto& i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
