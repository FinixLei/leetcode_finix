/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
    int max_valid = 0;
    int n = s.size();
    
    vector<int> vec;
    vec.reserve(n);
    int vec_pos = -1;
    int last_error_pos = -1; 

    int current_len = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') {  // record the position of every '('
            vec[++vec_pos] = i;
        }
        else {  // ')'
            if (vec_pos > 0) {  // still in some embeded '(' 
                current_len = i - vec[vec_pos-1];   // current length = current ')' postion - the position of the '(' before its own '('
                max_valid = max(max_valid, current_len);
                
                vec_pos --;
                if (vec_pos < 0) {
                    last_error_pos = i;
                }
            }
            else if (vec_pos == 0) {  // match to the only one '(', it means this '(', 0-N pairs have been matched 
                current_len = i - last_error_pos;  // so, do this 
                max_valid = max(max_valid, current_len);
                if (vec_pos == 0) vec_pos -- ;
            }
            else {  // vec_pos < 0 
                last_error_pos = i;  // update last_error_pos because this position is also error position of ')'
            }
        }
    }
    return max_valid; 
}
    
int main()
{
    string s = "(()";      // 2
    cout << s << ": " << longestValidParentheses(s) << endl;
    
    s = ")()())";   // 4
    cout << s << ": " << longestValidParentheses(s) << endl;
    
    s = "(()()";    // 4
    cout << s << ": " << longestValidParentheses(s) << endl;
    
    return 0;
}