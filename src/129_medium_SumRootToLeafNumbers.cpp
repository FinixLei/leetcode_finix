/*
    You are given the root of a binary tree containing digits from 0 to 9 only.

    Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
    Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

    A leaf node is a node with no children.

     

    Example 1:
        Input: root = [1,2,3]
        Output: 25
        Explanation:
        The root-to-leaf path 1->2 represents the number 12.
        The root-to-leaf path 1->3 represents the number 13.
        Therefore, sum = 12 + 13 = 25.
*/

void dfs(TreeNode * root, vector<int>& vec, int& result) {
    if (root == nullptr) return;
    
    vec.push_back(root->val);
    
    if (root->left == nullptr && root->right == nullptr) {
        int sum = 0; 
        for (int i=0; i<vec.size(); i++) {
            sum = sum*10 + vec[i]; 
        }
        result += sum; 
        
        vec.pop_back();
        return; 
    }
    
    if (root->left) dfs(root->left, vec, result);
    if (root->right) dfs(root->right, vec, result);
    vec.pop_back();
}

int sumNumbers(TreeNode* root) {
    vector<int> vec;
    int result = 0; 
    dfs(root, vec, result); 
    return result; 
}
