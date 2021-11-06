/*
    Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <string>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];
    
    string result; 
    int pos = 0;
    bool fail = false;
    for (; pos < strs[0].size(); pos++) {
        char ch = strs[0][pos];
        for (int j=1; j<strs.size(); j++) {
            if (ch != strs[j][pos]) {
                fail = true;
                break;
            }
        }
        
        if (fail) break;
        result.push_back(strs[0][pos]);
    }
    
    return result;
}

int main() {
    std::vector<string> vecstr = {
        "abcd", "abc", "abcde"
    };
    
    string longest = longestCommonPrefix(vecstr);
    
    std::cout << "The longest common prefix is: " << longest << std::endl;
    
    return 0;
}