/*
    Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <string>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int size = strs.size();
    string longest;
    
    if (size == 0) {
        longest = "";
    }
    else if (size == 1) {
        longest = strs[0]; 
    }
    else if (size >= 2) {
        longest = strs[0];
        char buffer[longest.length()+1];
        strcpy(buffer, longest.c_str());
        
        int len, pos;
        int move = 1; 
        while (move < size) {
            len = min(longest.length(), strs[move].length());            
            pos = 0;
            while (pos < len) {
                if (longest[pos] == strs[move][pos]) {
                    ++pos;
                } 
                else {
                    break;
                }
            }
            
            buffer[pos] = '\0';
            longest = string(buffer);
            ++ move;
        }
    }
    return longest;
}

int main() {
    std::vector<string> vecstr = {
        "abcd", "abc", "abcde"
    };
    
    string longest = longestCommonPrefix(vecstr);
    
    std::cout << "The longest common prefix is: " << longest << std::endl;
    
    return 0;
}