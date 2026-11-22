class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        const int size = q1.size();
        for (int i=0; i<size-1; i++) {
            int tmp = q1.front();
            q2.push(tmp);
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        swap(q1, q2);
        return val;
    }
    
    int top() {
        const int size = q1.size();
        for (int i=0; i<size-1; i++) {
            int tmp = q1.front();
            q2.push(tmp);
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        q2.push(val);
        swap(q1, q2);
        return val;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
