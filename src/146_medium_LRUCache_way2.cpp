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

// This way-2 does not satisfy with the time requirement.
// But it represents a kind of usage of STL. So, keep it here. 

class LRUCache {
private:
    int _capacity;
    int _size; 
    list<pair<int, int>> _list; 
    set<int> keySet; 

public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        _list = {};
        keySet = {};
    }
    
    int get(int key) {
        if (keySet.find(key) == keySet.end()) return -1;

        auto it = _list.begin();
        for(; it != _list.end(); it++) {
            if ((*it).first == key) {
                int result = it->second;
                if (it != _list.begin()) {
                    _list.erase(it);
                    _list.push_front(make_pair(key, result));
                }
                return result;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        bool bFind = false;
        if (keySet.find(key) == keySet.end()) bFind = false;
        else bFind = true;

        if (!bFind) {
            _list.push_front(make_pair(key, value));
            keySet.insert(key);

            if (_size == _capacity) {
                keySet.erase(_list.back().first);
                _list.pop_back();
            }
            else {
                _size ++;
            }
            return;
        }
        
        auto it = _list.begin();
        for(; it != _list.end(); it++) {
            if ((*it).first == key) {
                _list.erase(it);
                _list.push_front(make_pair(key, value));
                return;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */