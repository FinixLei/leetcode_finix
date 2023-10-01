/*
    A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
    Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
    For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
    Return the head of the copied linked list.

    The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
    Your code will only be given the head of the original linked list.

    Example 1:
        Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
        Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/


/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;

        // Records the node in original list to the node at the same position of the new list
        Map<Node, Node> nodeToNodeMap = new HashMap<>();

        Node p = head;
        Node newHead = new Node(p.val);
        Node q = newHead;
        nodeToNodeMap.put(p, q);

        // Step 1. Copy the whole list without random pointers
        while (p != null) {
            p = p.next;
            if (p != null) {
                q.next = new Node(p.val);
                q = q.next;
                nodeToNodeMap.put(p, q);
            }
            else {
                q = null;
            }
        }

        // Step 2. Setting random pointers with nodeToNodeMap
        p = head;
        q = newHead;
        while (p != null) {
            q.random = nodeToNodeMap.get(p.random);            
            p = p.next;
            q = q.next;
        }
        return newHead;
    }
}
