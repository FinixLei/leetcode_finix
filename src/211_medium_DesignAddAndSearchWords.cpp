class WordDictionary {
private:
    vector<set<string>> wordGroups;
    unordered_map<string, bool> cache;

public:
    WordDictionary() {
        for (int i=0; i<26; i++) {
            wordGroups.push_back({});
        }
    }
    
    void addWord(string word) {
        if (search(word)) return;
        wordGroups[word.size()].insert(word);
    }
    
    bool search(string word) {
        if (cache.contains(word)) return true;

        const int size = word.size();
        if (word.contains('.')) {
            for (auto& s : wordGroups[size]) {
                bool isSame = true;
                for (int i=0; i<size; i++) {
                    if (word[i] == '.') continue;
                    if (word[i] != s[i]) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) {
                    cache[word] = true;
                    return true;
                }
            }
            // cache does not record false, as it may be added later
            return false;
        }
        else {
            bool result = wordGroups[size].contains(word);
            if (result) cache[word] = true;
            return result;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */