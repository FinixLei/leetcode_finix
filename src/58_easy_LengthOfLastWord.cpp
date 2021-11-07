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

// way-2 
int lengthOfLastWord_way_2(string& s) 
{
    if (s.size() == 0) return 0;
    
    size_t last_space_index = s.find_last_of(" ");
    
    if (last_space_index == string::npos) {
        if (s[0] != ' ') return s.size();
        else return 0;
    }    
    if (last_space_index < s.size()-1) {
        return s.size()-1-last_space_index;
    }
    
    int i= last_space_index;
    for (; i>=0; i--) {
        if (s[i] != ' ') break;
    }
    if (i < 0) return 0;
    
    int result = 0;
    while (i>=0 && s[i] != ' ' && i>=0) {
        result ++;
        i--;
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
