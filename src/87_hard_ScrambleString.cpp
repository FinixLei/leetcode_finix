/*
    We can scramble a string s to get a string t using the following algorithm:

    If the length of the string is 1, stop.
    If the length of the string is > 1, do the following:
    Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
    Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
    Apply step 1 recursively on each of the two substrings x and y.
    Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
    
    Example 1:
        Input: s1 = "great", s2 = "rgeat"
        Output: true
        Explanation: One possible scenario applied on s1 is:
        "great" --> "gr/eat" // divide at random index.
        "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
        "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
        "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
        "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
        "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
        The algorithm stops now, and the result string is "rgeat" which is s2.
        As one possible scenario led s1 to be scrambled to s2, we return true.

    Example 2:
        Input: s1 = "abcde", s2 = "caebd"
        Output: false
        
    Example 3:
        Input: s1 = "a", s2 = "a"
        Output: true
*/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> memo; 


string genSortedString(string& s) {
    int size = s.size();
    if (size == 0 || size == 1) return s;
    
    vector<char> array;
    for (int i=0; i<size; i++) array.push_back(s[i]);
    
    sort(array.begin(), array.end());
    string result(array.begin(), array.end());
    return result; 
}

bool isScramble(string& s1, string& s2) {
    if (s1.size() != s2.size()) return false;
    if (s1.size() == 1) return s1 == s2; 
    
    string combined(s1);
    combined.append(s2);
    if (memo.find(combined) != memo.end()) return memo.at(combined);
    
    int size = s1.size();
    
    int part_length = 1; 
    
    while (part_length <= size/2) {
        string s1_k1_p1 = s1.substr(0, part_length); 
        string s1_k1_p2 = s1.substr(part_length);
        string s1_k2_p1 = s1.substr(size - part_length); 
        string s1_k2_p2 = s1.substr(0, size - part_length); 
        string s2_k1_p1 = s2.substr(0, part_length); 
        string s2_k1_p2 = s2.substr(part_length); 
        string s2_k2_p1 = s2.substr(size - part_length); 
        string s2_k2_p2 = s2.substr(0, size - part_length);

        string sorted_s1_k1_p1 = genSortedString(s1_k1_p1);
        string sorted_s1_k1_p2 = genSortedString(s1_k1_p2);
        string sorted_s1_k2_p1 = genSortedString(s1_k2_p1);
        string sorted_s1_k2_p2 = genSortedString(s1_k2_p2);
        string sorted_s2_k1_p1 = genSortedString(s2_k1_p1);
        string sorted_s2_k1_p2 = genSortedString(s2_k1_p2);
        string sorted_s2_k2_p1 = genSortedString(s2_k2_p1);
        string sorted_s2_k2_p2 = genSortedString(s2_k2_p2);
        
        if (sorted_s1_k1_p1 == sorted_s2_k1_p1 && sorted_s1_k1_p2 == sorted_s2_k1_p2) {
            if (isScramble(s1_k1_p1, s2_k1_p1) && isScramble(s1_k1_p2, s2_k1_p2)) {
                return true;
            }
        }
        
        if (sorted_s1_k2_p1 == sorted_s2_k1_p1 && sorted_s1_k2_p2 == sorted_s2_k1_p2) {
            if (isScramble(s1_k2_p1, s2_k1_p1) && isScramble(s1_k2_p2, s2_k1_p2)) {
                return true;
            }
        }  

        if (sorted_s1_k1_p1 == sorted_s2_k2_p1 && sorted_s1_k1_p2 == sorted_s2_k2_p2) {
            if (isScramble(s1_k1_p1, s2_k2_p1) && isScramble(s1_k1_p2, s2_k2_p2)) {
                return true;
            }
        }
        
        if (sorted_s1_k2_p1 == sorted_s2_k2_p1 && sorted_s1_k2_p2 == sorted_s2_k2_p2) {
            if (isScramble(s1_k2_p1, s2_k2_p1) && isScramble(s1_k2_p2, s2_k2_p2)) {
                return true;
            }
        }
        
        part_length ++;
    }
    
    memo[combined] = false;
    return false; 
}

int main()
{
    string s1 = "eebaacbcbcadaaedceaaacadccd";
    string s2 = "eadcaacabaddaceacbceaabeccd";
    
    bool result = isScramble(s1, s2);
    cout << "result = " << result << endl;

    return 0;
}
