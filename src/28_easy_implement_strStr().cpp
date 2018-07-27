/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack.size() < needle.size()) return -1;
        
        int size = needle.size();
        int last_pos = haystack.size() - needle.size(); 
        
        for (int i=0; i<=last_pos; ++i) {
            int j = 0;
            for (j=0; j<size; ++j) {
                if (haystack[i+j] != needle[j]) break;
            }
            if (j==size) return i;
        }
        
        return -1;
    }
};
