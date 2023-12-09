/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:
    Input
        ["MinStack","push","push","push","getMin","pop","top","getMin"]
        [[],[-2],[0],[-3],[],[],[],[]]
    Output
        [null,null,null,null,-3,null,0,-2]

    Explanation
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin(); // return -3
        minStack.pop();
        minStack.top();    // return 0
        minStack.getMin(); // return -2
*/

struct Node {
    int val;
    Node * next;
    Node(int v=0, Node* n=nullptr) : val(v), next(n) {}
};

class MinStack {
private:
    stack<Node *> _stack;
    Node * minListHead;

public:
    MinStack() {
        _stack = {};
        minListHead = nullptr;
    }
    
    void push(int val) {
        Node * p = new Node(val);
        // maintain the stack
        _stack.push(p);

        // maintain the sorted Linked List for Nodes
        if (minListHead == nullptr || minListHead->val >= val) {
            p->next = minListHead;
            minListHead = p;
            return;
        }
        Node * tmp = minListHead;
        while (tmp != nullptr) {
            if (tmp->next != nullptr) {
                if (tmp->val <= val && val < tmp->next->val) {
                    p->next = tmp->next;
                    tmp->next = p;
                    return;
                } 
                else {
                    tmp = tmp->next;
                }
            } 
            else {  // tmp->next == nullptr
                if (tmp->val <= val) {
                    p->next = nullptr;
                    tmp->next = p;
                } 
                else {
                    // Never get here
                }
                return;
            }
        }
    }
    
    void pop() {
        Node * p = _stack.top();
        _stack.pop();

        if (minListHead == p) {
            minListHead = minListHead->next;
        }
        else {
            Node *p1 = minListHead;
            Node *p2 = p1->next;
            while (p2 != p && p2!=nullptr) {
                p1 = p2;
                p2 = p2->next;
            }
            if (p2 == nullptr) return;
            p1->next = p2->next;
        }
        delete p;
    }
    
    int top() {
        return (_stack.top())->val;
    }
    
    int getMin() {
        return minListHead->val;
    }
};
