/*
    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    The functions get and put must each run in O(1) average time complexity.

    Example 1:
    Input
        ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
        [null, null, null, 1, null, -1, null, -1, 3, 4]
*/

struct Node {
    int key;
    int val;
    Node * prev;
    Node * next;
    
    Node(int k, int v) : key(k), val(v) {
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int _capacity;
    int _size; 

    // use head and tail to construct a doubly linked list but no need to be looped. 
    Node * head;
    Node * tail;

    // find out the Node pointer quickly for moving to head and for get()
    unordered_map<int, Node *> _map;

private:
    void moveToHead(Node * p) {
        if (p->prev == head) return;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = head->next;
        p->prev = head;
        head->next->prev = p;
        head->next = p;
    }

public:
    LRUCache(int capacity) : _capacity(capacity) {
        _size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node * h = head;
        while (h != tail) {
            Node * tmp = h->next;
            delete h;
            h = tmp;
        }
        delete tail;
    }
    
    int get(int key) {
        auto iter = _map.find(key);
        if (iter != _map.end()) { // find the key
            Node * p = iter->second;
            moveToHead(p);
            return p->val;
        }
        return -1;
    }
    
    void put(int key, int value) {  // only modify _map in put(), no need to use it
        auto iter = _map.find(key);
        if (iter == _map.end()) {  // key is not found 
            Node * p = new Node(key, value);
            p->next = head->next;
            p->prev = head;
            head->next->prev = p;
            head->next = p;

            _map.insert(make_pair(key, p));

            if (_size == _capacity) {
                Node * last = tail->prev;
                last->prev->next = tail;
                tail->prev = last->prev;
                _map.erase(last->key);
                delete last;
            }
            else {
                _size ++;
            }
            return;
        }
        else { // find the key
            Node *p = iter->second; 
            p->val = value;
            moveToHead(p);
        }
    }
};
