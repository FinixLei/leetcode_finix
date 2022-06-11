/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example 1:
    Input: root = [1,2,3,4,5,null,7]
    Output: [1,#,2,3,#,4,5,7,#]
Explanation: 
    Given the above binary tree (Figure A), 
    your function should populate each next pointer to point to its next right node, 
    just like in Figure B. The serialized output is in level order as connected by the next pointers, 
    with '#' signifying the end of each level.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


void layeredLoop(Node * root, vector<pair<int, Node *>>& vec) {
    if (root == nullptr) return;
    
    queue<pair<int, Node *>> myqueue; 
    myqueue.push(make_pair(1, root));
    
    while(!myqueue.empty()) {
        pair<int, Node *> tmp = myqueue.front();
        vec.push_back(tmp);
        myqueue.pop();
        
        int currLayer = tmp.first + 1;
        if (tmp.second->left)  myqueue.push({currLayer, tmp.second->left});
        if (tmp.second->right) myqueue.push({currLayer, tmp.second->right});
    }
}

Node* connect(Node* root) 
{
    vector<pair<int, Node *>> vec; 
    layeredLoop(root, vec);
    
    if (vec.size() == 0) return root; 
    
    for (int i=0; i<vec.size()-1; i++) {
        if (vec[i].first == vec[i+1].first) {
            vec[i].second->next = vec[i+1].second;
        }
    }
    
    return root;
}
