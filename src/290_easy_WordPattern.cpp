/*
    Given a pattern and a string str, find if str follows the same pattern.

    Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

    Examples:
    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.
    Notes:
    You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int pattern_size = pattern.length();
        const char * pch = pattern.c_str();
        
        istringstream iss(str);
        vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};
        if (pattern_size != words.size()) return false;
        
        map<char, string> my_map; 
        map<string, char> invert_map;
        
        for (int i=0; i<pattern_size; i++) {
            if (my_map.find(pch[i]) == my_map.end()) {
                my_map[pch[i]] = words[i];
            } else {
                if (my_map[pch[i]] != words[i]) {
                    return false;
                }
            }
            
            if (invert_map.find(words[i]) == invert_map.end()) {
                invert_map[words[i]] = pch[i];
            } else {
                if (invert_map[words[i]] != pch[i]) {
                    return false;
                }
            }
        }
    
        return true;
    }
};
