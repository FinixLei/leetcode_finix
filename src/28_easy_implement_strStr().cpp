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
        int s1 = haystack.size();
        int s2 = needle.size();
        if (s2 == 0) return 0;
        if (s1 == 0 || s1 < s2) return -1;
        
        for (int i=0; i<=s1-s2; i++) {
            int j = 0;
            for (; j<s2; j++) {
                if (haystack[i+j] != needle[j]) break;
            }
            if (j == s2) return i;
        }
        return -1;
    }
};
