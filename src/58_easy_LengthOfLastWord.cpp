/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5

Example 2:
Input: s = " "
Output: 0
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        const int size = s.size();
        if (size == 0) return 0;

        int i = size-1;
        while (s[i] == ' ') {
            i --;
        }

        int count = 0;
        while (i >= 0 && s[i] != ' ') {
            count ++;
            i --;
        }

        return count;
    }
};