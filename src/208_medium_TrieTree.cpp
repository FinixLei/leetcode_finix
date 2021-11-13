/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:
- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
- boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 
*/


#include <iostream>
#include <cstring>
using namespace std;

struct TNode {
    char val;
    bool isEnded;
    TNode * nextNodes[26];
    
    TNode(char v='\0', bool e=true) : val(v), isEnded(e) {
        for (int i=0; i<26; i++) nextNodes[i] = nullptr;
    }
};

class Trie {
private:
    struct TNode * head;
    
public:
    Trie() {
        head = new TNode;
    }
    
    ~Trie() {
        delete head;
    }
    
    void _printTrie(TNode * p) {
        if (p == nullptr) return;
        
        for (int i=0; i<26; i++) {
            if (p->nextNodes[i]) {
                cout << "(" << i << ": " << p->nextNodes[i]->val << ") ";
                _printTrie(p->nextNodes[i]);
            }
        }
    }
    
    void printTrie() {
        _printTrie(head);
        cout << endl;
    }
    
    void insert(string word) {
        if (word.size() == 0) return;
        
        TNode * p = head;
        for (int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            
            if (p->nextNodes[index] == nullptr) {
                p->nextNodes[index] = new TNode(word[i]);
                if (i < word.size()-1) p->nextNodes[index]->isEnded = false;
                p = p->nextNodes[index];
            }
            else {
                // No need to check val 
                p = p->nextNodes[index];
                if (i == word.size() - 1) p->isEnded = true;
            }
        }
    }
    
    bool search(string word) {
        if (word.size() == 0) return true;
        
        bool result = false;
        TNode * p = head;
        for (int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if (p->nextNodes[index]) {
                if (i == word.size()-1) {
                    result = p->nextNodes[index]->isEnded ? true : false;
                    break;
                }
                p = p->nextNodes[index];
            }
            else {
                result = false;
                break;
            }
        }
        return result;
    }
    
    bool startsWith(string prefix) {
        if (prefix.size() == 0) return true;
        
        bool result = false;
        TNode * p = head;
        for (int i=0; i<prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (p->nextNodes[index]) {
                if (i == prefix.size()-1) {
                    return true;
                }
                p = p->nextNodes[index];
            }
            else {
                return false;
            }
        }
        return result;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.printTrie();
    cout << std::boolalpha << trie.search("apple") << endl;  // true 
    cout << std::boolalpha << trie.search("app") << endl;     // false
    cout << std::boolalpha << trie.startsWith("app") << endl;   // true
    trie.insert("app");
    cout << std::boolalpha << trie.search("app") << endl;     // true
    
    cout << "----------------" << endl;
    Trie t2;
    t2.insert("a");
    cout << std::boolalpha << t2.search("a") << endl;
    cout << std::boolalpha << t2.startsWith("a") << endl;

    return 0;
}
