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

#include <string>
#include <iostream>
using namespace std;

int lengthOfLastWord(string& s) 
{
    int result = 0;
    int last_index = s.size()-1;
    int last_pos = -1;  // <0 means not started
    
    int i = last_index;
    for (; i>=0; --i)
    {
        if (s[i] != ' ' && last_pos < 0) {
            last_pos = i;
            continue;
        }
        
        if (s[i] == ' ' && last_pos > 0) {
            result = last_pos - i;
            break;
        }
    }
    
    if (last_pos >= 0 && i < 0) {
        result = last_pos + 1;
    }
    
    return result; 
}

int main()
{
    string s = "Hello World";
    cout << s << ": \n" << lengthOfLastWord(s) << endl;
    
    s = " ";
    cout << s << ": \n" << lengthOfLastWord(s) << endl;
    
    s = "a  ";
    cout << s << ": \n" << lengthOfLastWord(s) << endl;
    
    s = "a";
    cout << s << ": \n" << lengthOfLastWord(s) << endl;
    
    s = "  a";
    cout << s << ": \n" << lengthOfLastWord(s) << endl;
    
    return 0;
}
