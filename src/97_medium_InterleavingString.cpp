/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:
    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

struct starts {
    int b1;
    int b2;
    int b3;
    
    starts(int d1=0, int d2=0, int d3=0) : b1(d1), b2(d2), b3(d3) {}
    
    bool operator == (const starts & other) const {
        return b1==other.b1 && b2==other.b2 && b3==other.b3;
    }
};


struct hash_func
{
    std::size_t operator() (const starts & pos) const {
        return (pos.b1 << 16) | (pos.b2 << 8) | pos.b3; 
    }
};

unordered_map<starts, bool, hash_func> cache;

bool _helper(string& s1, string& s2, string& s3, starts pos) 
{
    int beg1 = pos.b1; 
    int beg2 = pos.b2; 
    int beg3 = pos.b3;
    
    // cout << "beg1 = " << beg1 << ", beg2 = " << beg2 << ", beg3 = " << beg3 << endl;
    
    if (beg1 == s1.length() && beg2 == s2.length() && beg3 == s3.length()) {
        return true;
    }
    
    if (cache.find(pos) != cache.end()) {
        return cache[pos];
    }
    
    if (beg1 == s1.length()) {
        int count = s2.length()-beg2; 
        for (int i=0; i<count; i++) {
            if (s2[beg2+i] != s3[beg3+i]) {
                cache[pos] = false;
                return false;
            }
        }
        cache[pos] = true;
        return true;
    }
    
    if (beg2 == s2.length()) {
        int count = s1.length()-beg1; 
        for (int i=0; i<count; i++) {
            if (s1[beg1+i] != s3[beg3+i]) {
                cache[pos] = false;
                return false;
            }
        }
        cache[pos] = true;
        return true;
    }
    
    if (s1[beg1] == s3[beg3]) {
        bool r1 = _helper(s1, s2, s3, {beg1+1, beg2, beg3+1});
        if (r1 == true) {
            cache[pos] = true;
            return true;
        }
    }
    
    if (s2[beg2] == s3[beg3]) {
        bool r2 = _helper(s1, s2, s3, {beg1, beg2+1, beg3+1});
        if (r2 == true) {
            cache[pos] = true;
            return true;
        }
    }
    
    cache[pos] = false;
    return false; 
}

 bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) return false;
    
    // Acceleration
    unordered_map<char, int> m1, m2, m3;
    for(int i=0; i<s1.length(); i++) m1[s1[i]] ++;
    for(int i=0; i<s2.length(); i++) m2[s2[i]] ++;
    for(int i=0; i<s3.length(); i++) m3[s3[i]] ++;
    
    for (auto it=m2.begin(); it!=m3.end(); it++) {
        if (m3[it->first] != m1[it->first] + m2[it->first]) return false;
    }
    
    // Normal Handling
    return _helper(s1, s2, s3, {0, 0, 0});
}

int main() 
{
    string s1, s2, s3;
    bool result = false;
    
    // true 
    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    
    // false
    s1 = "aacaac";
    s2 = "aacaaeaac";
    s3 = "aacaaeaaeaacaac";
    
    // false
    s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";

    result =  isInterleave(s1, s2, s3);
    cout << "result = " << std::boolalpha << result << endl;
    
    return 0;
}
