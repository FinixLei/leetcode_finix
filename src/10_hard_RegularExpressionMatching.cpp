/* 
    Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.
    The matching should cover the entire input string (not partial).

    Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.
    Example 1:

    Input:
    s = "aa"
    p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    Example 2:

    Input:
    s = "aa"
    p = "a*"
    Output: true
    Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
    Example 3:

    Input:
    s = "ab"
    p = ".*"
    Output: true
    Explanation: ".*" means "zero or more (*) of any character (.)".
    Example 4:

    Input:
    s = "aab"
    p = "c*a*b"
    Output: true
    Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
    Example 5:

    Input:
    s = "mississippi"
    p = "mis*is*p*."
    Output: false
*/

#include <string>
#include <iostream>
using namespace std;


bool _is_match(int ** memo, string& s, string& p, int si, int pi)
{
    if (memo[si][pi] != -1) return memo[si][pi] == 1; 
    
    bool result = false; 
    int sn = s.size();
    int pn = p.size();
    
    if (pi >= pn) {
        result = (si >= sn);
    }
    else {
        bool firstMatch = ( si<sn && (s[si]==p[pi] || p[pi] == '.') );
        
        if (pi+1 < pn && p[pi+1] == '*') {
            result = ( (firstMatch && _is_match(memo, s, p, si+1, pi)) || _is_match(memo, s, p, si, pi+2) );
        }
        else {
            result = ( firstMatch && _is_match(memo, s, p, si+1, pi+1) );
        }
    }
    
    memo[si][pi] = (result ? 1 : 0);
    return result; 
}

bool isMatch(string& s, string& p)
{
    const int sn = s.size() + 1;
    const int pn = p.size() + 1;
    int ** memo = new int * [sn];
    
    for (int i=0; i<sn; i++) {
        memo[i] = new int [pn];
        for (int j=0; j<pn; j++) {
            memo[i][j] = -1;
        }
    }
    bool result = _is_match(memo, s, p, 0, 0);
    
    for (int i=0; i<sn; i++) delete [] memo[i];
    delete [] memo;
    
    return result;
}


int main()
{
    string s, p;
    bool result = false;
    
    s = "aaa";
    p = "a*a";
    result = isMatch(s, p);
    cout << "s=" << s << ", p=" << p << "\n" << (result ? string("true") : string("false") ) << endl;
    
    s = "aa";
    p = "a*";
    result = isMatch(s, p);
    cout << "s=" << s << ", p=" << p << "\n" << (result ? string("true") : string("false") ) << endl; 
    
    return 0;
}
