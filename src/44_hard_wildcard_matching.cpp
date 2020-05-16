/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

*/

#include <iostream>
#include <set>
#include <string>
using namespace std;


bool mymatch(const string& s, const string& p, int si, int pi, set<pair<int, int>>& cache) {
    bool result = false;
    
    int s_size = s.size() - si;;
    int p_size = p.size() - pi;
    
    if (s_size == 0 && p_size == 0) {
        return true;
    }
    else if (s_size > 0 && p_size == 0) {
        return false;
    }
    else if (s_size == 0 && p_size > 0) {
        for (int i=pi; i<p.size(); i++) {
            if (p[i] != '*') return false;
        }
        return true;
    }
    
    while (true) {
        if (p[pi] != '*' && p[pi] != '?') {
            if (s[si] != p[pi]) {
                result = false;
                break;
            }
            else {
                pi ++;
                si ++;
            }
        }
        
        else if (p[pi] == '?') {
            pi ++;
            si ++;
        }
        
        else {  // if (p[pi] == '*')
            if (pi == p.size()-1) {
                result = true;
                break;
            }
            else {
                bool match_star = false;
                
                while ( (p[pi] == '*' || p[pi] == '?') && pi < p.size() ) {
                    if (p[pi] == '*') {
                        pi ++;
                    }
                    else if(p[pi] == '?') {
                        pi ++;
                        si ++;
                        if (si == s.size()) {
                            for (int k=pi; k<p.size(); k++) {
                                if (p[k] != '*') return false;
                            }
                            return true;
                        }
                    }
                }
                if (pi == p.size()) return true;
                
                for (int i=si; i<s.size(); i++) {
                    // cout << "i = " << i << ", pi = " << pi << endl;
                    if (s[i] == p[pi]) {
                        // Look up <si, pi> in the cache
                        pair<int, int> tgt_pair(i, pi);
                        if ( cache.find(tgt_pair) != cache.end() ) { 
                            return false;
                        }
                        
                        if ( mymatch(s, p, i, pi, cache) ) {
                            return true;
                        }
                        else {
                            // record the failure pair to set 
                            cache.insert(tgt_pair);
                        }
                    }
                }
                result = false;
                break;
            }
        }
        
        if (pi == p.size() && si == s.size()) {
            result = true; 
            break;
        }
        else if (pi == p.size() && si < s.size()) {
            result = false;
            break;
        }
        else if (pi < p.size() && si == s.size()) {
            for (int k=pi; k<p.size(); k++) {
                if (p[k] != '*') return false;
            }
            result = true;
            break;
        }
        else {
            // do nothing
        }
    }
    
exit:
    return result;
}

bool isMatch(string s, string p) {
    set<pair<int, int>> cache;
    return mymatch(s, p, 0, 0, cache);
}

# define CHECK_IF_SHOULD_MATCH(bShould)     \
    if ( isMatch(s, p) == (bShould) ) {     \
        cout << "Correct: they do " << (bShould ? "":"not ") << "match: \n"; \
        cout << "   s=" << s << endl;       \
        cout << "   p=" << p << endl;       \
    }                           \
    else {                      \
        cout << "Wrong: they should " << (bShould ? "" : "not ")   \
             << "match but " << (bShould ? "not" : "do") << ":\n"; \
        cout << "   s=" << s << endl;       \
        cout << "   p=" << p << endl;       \
    }

int main()
{
    string s, p;
    
    s = "aa";
    p = "a";
    CHECK_IF_SHOULD_MATCH(false)
    
    s = "adceb";
    p = "*a*b";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "aaaa";
    p = "***a";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "";
    p = "";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "";
    p = "*";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "a";
    p = "a*";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "c";
    p = "*?*";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "hi";
    p = "*?";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "abefcdgiescdfimde";
    p = "ab*cd?i*de";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "mississippi";
    p = "m*iss*";
    CHECK_IF_SHOULD_MATCH(true)
    
    s = "mississippi";
    p = "m??*ss*?i*pi";
    CHECK_IF_SHOULD_MATCH(false)
    
    s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
    p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
    CHECK_IF_SHOULD_MATCH(false)
    
    s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
    p = "b*bb*a*bba*b*a*bbb*aba*babbb*aa*aabb*bbb*a";
    CHECK_IF_SHOULD_MATCH(false)
    
    
    s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    CHECK_IF_SHOULD_MATCH(false)

    return 0;
}
