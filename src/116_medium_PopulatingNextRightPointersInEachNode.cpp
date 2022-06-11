/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example 1:
    Input: root = [1,2,3,4,5,6,7]
    Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: 
    Given the above perfect binary tree (Figure A), 
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


void layeredLoop(Node * root, vector<Node *>& vec) {
    if (root == nullptr) return;
    
    queue<Node *> myqueue; 
    
    myqueue.push(root);
    while(!myqueue.empty()) {
        Node * tmp = myqueue.front();
        vec.push_back(tmp);
        myqueue.pop();
        
        if (tmp->left) myqueue.push(tmp->left);
        if (tmp->right) myqueue.push(tmp->right);
    }
}

Node* connect(Node* root) 
{
    vector<Node *> vec; 
    layeredLoop(root, vec);
    
    int layer = 1; 
    int layerEndIndex = 0; 
    for (int i=0; i<vec.size(); i++) {
        if (i == layerEndIndex) {
            layer ++;
            layerEndIndex = (1 << layer) - 2;
            continue; 
        }
        
        if (i < vec.size() - 1) {
            vec[i] -> next = vec[i+1];
        }
    }
    
    return root;
}
