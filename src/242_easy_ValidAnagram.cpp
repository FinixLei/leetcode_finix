/*
    Given two strings s and t, write a function to determine if t is an anagram of s.

    For example,
    s = "anagram", t = "nagaram", return true.
    s = "rat", t = "car", return false.

    Note:
    You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int total_length = s.length();
        
        const char * s1 = s.c_str();
        const char * s2 = t.c_str();
        
        const int size = 128;
        
        int a1[size];
        int a2[size];
        
        for (int i=0; i<size; i++) {
            a1[i] = a2[i] = 0;
        }
        
        for (int i=0; i<total_length; i++) {
            a1[s1[i]] ++;
            a2[s2[i]] ++;
        }
        
        for (int i=0; i<size; i++) {
            if (a1[i] != a2[i]) return false;
        }
        
        return true;
    } 
    
    bool isAnagram_way2(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
