/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
*/


class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for (char ch : s) {
            if (('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9')) {
                newStr.push_back(ch);
            }
            else if ('A' <= ch && ch <= 'Z') {
                ch = ch - ('A' - 'a');
                newStr.push_back(ch);
            }
            else {
                // do nothing
            }
        }
        
        if (newStr.empty()) return true;
        
        int i=0, j=newStr.size()-1;
        while (i < j) {
            if (newStr[i++] != newStr[j--]) return false;
        }
        return true;
    }
};