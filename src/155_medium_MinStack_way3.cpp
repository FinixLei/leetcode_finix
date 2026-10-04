struct Node {
    int val; 
    Node * next;
    Node(int v, Node *n=nullptr) : val(v), next(n) {}
};

class MinStack {
private:
    vector<int> data;
    Node * sp = nullptr;

    // return index of the value or -1
    int search_value(int value, int curr_idx) {
        if (curr_idx >= data.size()) return -1;
        if (data[curr_idx] == value) return curr_idx;
        if (data[curr_idx] < value) {
            int r1 = search_value(value, curr_idx*2+1);
            if (r1 > 0) return r1;
            int r2 = search_value(value, curr_idx*2+2);
            return r2 == -1 ? -1 : r2;
        }
        return -1;
    }

    void sift_up() {
        int i = data.size() - 1;
        while (true) {
            int parent = (i-1) / 2;
            if (parent < 0) break;
            if (data[parent] <= data[i]) break;
            swap(data[parent], data[i]);
            i = parent;
        }
    }

    void sift_down(int i) {
        int left = i*2+1;
        int right = left + 1;
        const int size = data.size();
    
        while (true) {
            if (left >= size) return;
            int min_idx = -1;
            if (right < size) min_idx = data[left] <= data[right] ? left : right;
            else min_idx = left;
            if (data[i] <= data[min_idx]) return;
            swap(data[i], data[min_idx]);
            i = min_idx;
            left = i*2+1;
            right = left+1;
        }
    }

public:
    MinStack() { }
    
    void push(int value) {
        data.push_back(value);
        sift_up();
        Node * p = new Node(value);
        if (sp == nullptr) sp = p;
        else {
            p->next = sp;
            sp = p;
        }
    }
    
    void pop() {
        int data_idx = search_value(sp->val, 0);
        if (data_idx == -1) return;
        swap(data[data_idx], data[data.size()-1]);
        data.pop_back();
        sift_down(data_idx);

        Node * np = nullptr;
        if (sp) {
            np = sp->next;
            delete sp;
            sp = np;
        }
    }
    
    int top() {
        return sp->val;
    }
    
    int getMin() {
        return data[0];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */