#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define NO_NODE_VAL_NUM -9999

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void layered_print_tree(TreeNode * root) {
    if (root == nullptr) return;
    
    vector<int> result;
    
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    
    while (!nodeQueue.empty()) {
        TreeNode * tmp = nodeQueue.front();
        nodeQueue.pop();
        
        if (tmp == nullptr) {
            result.push_back(NO_NODE_VAL_NUM);
        }
        else {
            result.push_back(tmp->val);
            
            if (tmp->left == nullptr && tmp->right == nullptr) continue; 
            
            nodeQueue.push(tmp->left);
            nodeQueue.push(tmp->right);
        }
    }
    
    while (!result.empty() and result.back() == NO_NODE_VAL_NUM) {
        result.pop_back();
    }
    
    cout << "[";
    
    for(int i=0; i<result.size(); i++) {
        if (result[i] != NO_NODE_VAL_NUM) cout << result[i];
        else cout << "null"; 
        if (i != result.size()-1 ) cout << ", "; 
    }
    
    cout << "]";
}

void print_trees(const vector<TreeNode *> & vec) {
    cout << "There are " << vec.size() << " trees generated" << endl;
    
    cout << "["; 
    for (int i=0; i<vec.size(); i++) {
        layered_print_tree(vec[i]);
        if (i < vec.size()-1) cout << ", ";
    }
    cout << "]" << endl;
}

void destruct_tree(TreeNode * root) {
    if (root == nullptr) return;
    destruct_tree(root->left);
    destruct_tree(root->right);
    delete root;
}

//
// This function generates trees based on the given consequencial numbers
// 
// Parameters:
//      int beg       the begin number 
//      int end       the end number 
// Return:
//      A vector of TreeNode *
//      Each element is one tree's root 
//      Each tree contains all the numbers from beg to end 
//      Each number in [beg, end] could be root 
//
vector<TreeNode *> _genTreesBasedOnNums(int beg, int end) {
    vector<TreeNode *> trees;
    
    // Not possible, add nullptr to tree
    if(beg > end) {
        trees.push_back(nullptr);
        return trees;
    }
    // Only one element in the subtree, so just add it
    if(beg == end) {
        trees.push_back(new TreeNode(beg));
        return trees;
    }
    
    for(int i=beg; i<=end; i++) {
        // Each element in the 2 vectors stands for one Tree 
        vector<TreeNode *> leftTrees  = _genTreesBasedOnNums(beg, i-1);
        vector<TreeNode *> rightTrees = _genTreesBasedOnNums(i+1, end);
        
        for(int j=0; j<leftTrees.size(); j++) {
            for(int k=0; k<rightTrees.size(); k++) {
                TreeNode * root = new TreeNode(i);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
                trees.push_back(root);
            }
        }
    }
    return trees;
}

vector<TreeNode *> generateTrees(int n) {
    return _genTreesBasedOnNums(1, n);
}


int main()
{
    vector<TreeNode *> trees = generateTrees(3);
    print_trees(trees);
    
    for (auto & pTreeNode : trees) {
        destruct_tree(pTreeNode);
    }
    
    return 0;
}
