/*
    Given a reference of a node in a connected undirected graph.
    Return a deep copy (clone) of the graph.
    Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

    class Node {
        public int val;
        public List<Node> neighbors;
    }

    Test case format:
    For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

    An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
    The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

    Example 1:
        Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
        Output: [[2,4],[1,3],[2,4],[1,3]]
        Explanation: There are 4 nodes in the graph.
        1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
        2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
        3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
        4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
    
    Example 2:
        Input: adjList = [[]]
        Output: [[]]
        Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
    
    Example 3:
        Input: adjList = []
        Output: []
        Explanation: This an empty graph, it does not have any nodes.
*/


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private:
    void helper(unordered_map<int, Node *>& nodeMap, set<int>& visited, Node * node) {
        if (node == nullptr) return;
        if (visited.find(node->val) != visited.end()) return;
        
        if (nodeMap.find(node->val) == nodeMap.end()) {
            nodeMap[node->val] = new Node(node->val);
        }
        Node * curr = nodeMap[node->val];
        
        for (auto& p : node->neighbors) {
            if (nodeMap.find(p->val) == nodeMap.end()) {
                nodeMap[p->val] = new Node(p->val);
            }
            curr->neighbors.push_back(nodeMap[p->val]);
        }
        
        visited.insert(node->val);
        
        for (auto& p : node->neighbors) {
            helper(nodeMap, visited, p);
        }
    }
    
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        Node * n1 = new Node(node->val);
            
        unordered_map<int, Node *> newNodeMap; 
        newNodeMap[1] = n1; 
        
        set<int> visited; 
        helper(newNodeMap, visited, node);
        
        return n1;
    }
};
