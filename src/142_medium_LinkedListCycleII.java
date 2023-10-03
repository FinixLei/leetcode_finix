/*
    Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
    Do not modify the linked list.

    Example 1:
        Input: head = [3,2,0,-4], pos = 1
        Output: tail connects to node index 1
        Explanation: There is a cycle in the linked list, where tail connects to the second node.

    Example 2:
        Input: head = [1,2], pos = 0
        Output: tail connects to node index 0
        Explanation: There is a cycle in the linked list, where tail connects to the first node.

    Example 3:
        Input: head = [1], pos = -1
        Output: no cycle
        Explanation: There is no cycle in the linked list.
*/


/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) return null;
        if (head.next == head) return head;

        Set<ListNode> nodeSet = new HashSet<>();
        ListNode p1 = head;
        ListNode p2 = p1.next;  // init pos of p2 is one step ahead of p1
        nodeSet.add(p1);

        while (true) {
            p1 = p1.next; 
            nodeSet.add(p1);

            p2 = p2.next; 
            if (p2 == null) return null;
            if (nodeSet.contains(p2)) return p2;
            
            p2 = p2.next;
            if (p2 == null) return null;
            if (nodeSet.contains(p2)) return p2;            
        } 
    }
}