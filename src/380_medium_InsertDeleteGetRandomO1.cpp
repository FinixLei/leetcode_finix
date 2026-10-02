class RandomizedSet {
private:
    unordered_map<int, int> _map;
    vector<int> _vec;
    
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (_map.contains(val)) return false;
        _vec.push_back(val);
        _map[val] = _vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!_map.contains(val)) return false;
        int pos = _map[val];
        swap(_vec[pos], _vec[_vec.size()-1]);
        _map[_vec[pos]] = pos;
        _map.erase(val);
        _vec.pop_back(); 
        return true;
    }
    
    int getRandom() {
        return _vec[rand() % _vec.size()];
    }
};
