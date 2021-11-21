/*
    Given a string S, find the longest palindromic substring in S. 
    You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include <cstring>
#include <iostream>
using namespace std;

inline bool _check(const string& s, int i, int j) {
    if (i==j) return true;
    while (i<j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

string longestPalindrome(string s) {
    int size = s.size();
    if (size == 0 ||size == 1) return s;
    
    int maxLength = 0;
    int beg = 0, end = 0;
    
    for(int i=0; i<size; i++) {
        if (size-i <= maxLength) break;
        
        int j = s.find_last_of(s[i]);
        while (i < j) {
            if (_check(s, i, j)) {
                int length = j-i+1;
                if (maxLength < length) {
                    maxLength = length;
                    beg = i; 
                    end = j;
                }
                break;
            }
            else {
                j = s.find_last_of(s[i], j-1);
            }
        }
        
    }
    string result;
    copy(s.begin()+beg, s.begin()+end+1, back_inserter(result));
    return result;
}


int main()
{
    cout << longestPalindrome("abadd") << endl;
}