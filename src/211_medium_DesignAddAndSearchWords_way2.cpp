struct Node {
    bool bEnd;
    vector<Node *> children;
    Node() : bEnd(false), children(26, nullptr) {}
};

class WordDictionary {
private:
    Node * root;

    bool dfs(const string& word, int idx, Node * node) {
        if (idx == word.size()) return node->bEnd;

        char ch = word[idx];
        if (ch == '.') {
            for (Node * p : node->children) {
                if (p != nullptr && dfs(word, idx+1, p)) return true;
            }
            return false;
        }
        else {
            int pos = ch - 'a';
            if (node->children[pos] == nullptr) return false;
            return dfs(word, idx+1, node->children[pos]);
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node * cur = root;

        for (char ch : word) {
            int pos = ch - 'a';
            if (cur->children[pos] == nullptr) {
                cur->children[pos] = new Node();
            }
            cur = cur->children[pos];
        }
        cur->bEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

