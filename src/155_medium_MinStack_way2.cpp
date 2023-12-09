struct Node {
    int val;
    int minValueUntilNow;
    Node * next;
    Node(int v=0, Node* n=nullptr) : val(v), next(n) {
        minValueUntilNow = val;
    }
};

class MinStack {
private:
    Node * head;

public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        Node * p = new Node(val);
        if (head) {
            if (head->minValueUntilNow < p->minValueUntilNow) {
                p->minValueUntilNow = head->minValueUntilNow;
            }
        }
        p->next = head;
        head = p;
    }
    
    void pop() {
        Node * p = head;
        if (head) {
            head = head->next;
            delete p;
        }
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minValueUntilNow;
    }

    ~MinStack() {
        while (head) {
            Node *p = head;
            head = head->next;
            delete p;
        }
    }
};
