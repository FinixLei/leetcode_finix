/*
A valid number can be split up into these components (in order):
1. A decimal number or an integer.
2. (Optional) An 'e' or 'E', followed by an integer.

A decimal number can be split up into these components (in order):
1. (Optional) A sign character (either '+' or '-').
2. One of the following formats:
    2.1 At least one digit, followed by a dot '.'.
    2.2 At least one digit, followed by a dot '.', followed by at least one digit.
    2.3 A dot '.', followed by at least one digit.
    
An integer can be split up into these components (in order):
1. (Optional) A sign character (either '+' or '-').
2. At least one digit.

For example, 
all the following are valid numbers: 
    ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
while the following are not valid numbers: 
    ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
*/

#include <string>
#include <iostream>
using namespace std;


bool isDigit(string &s, int start, int end)
{
    if (end <= start) return false; 
    
    int i = start;
    for (; i<end; i++) {
        if (s[i] < '0' || s[i] > '9') {
            break;
        }
    }
    return i==end; 
}

bool isInteger(string &s, int start, int end)
{
    if (end <= start) return false; 
    
    if (s[start] == '+' || s[start] == '-') {
        start ++;
    }
    return isDigit(s, start, end);
}

bool isDecimalNumber(string &s, int start, int end)
{
    if (end <= start) return false; 
    
    if (s[start] == '+' || s[start] == '-') {
        start ++;
    }
    if (end <= start) return false; 

    int dot_count = 0;
    int dot_pos = -1;
    
    for (int i = start; i<end; i++) {
        if (s[i] == '.') {
            dot_count ++;
            if (dot_count > 1) return false; 
            dot_pos = i;
        }
    }
    if (dot_count == 0) return false;
    
    bool result = false; 
    
    if (dot_pos == start) {
        result = isDigit(s, start+1, end);
    }
    else if (dot_pos == end - 1) {
        result = isDigit(s, start, end-1);
    }
    else {
        bool r1 = isDigit(s, start, dot_pos);
        bool r2 = isDigit(s, dot_pos+1, end);
        result = r1 && r2 ;
    }
    return result; 
}

bool isNumber(string& s) 
{
    bool result = false;
    int size = s.size();
    int e_count = 0;
    int e_pos = -1;
    
    for (int i=0; i < size; i++){
        if (s[i] == 'e' || s[i] == 'E') {
            e_count ++;
            if (e_count > 1) return false;
            e_pos = i;
        }
    }
    
    bool r1 = false, r2 = false, r3 = false; 
    if (e_count == 0) {
        r1 = isDecimalNumber(s, 0, size);
        r2 = isInteger(s, 0, size);
        result = (r1 || r2);
    }
    else {  // e_count == 1
        if (e_pos == size-1) return false; 
        
        r1 = isDecimalNumber(s, 0, e_pos);
        r2 = isInteger(s, 0, e_pos);
        r3 = isInteger(s, e_pos+1, size);
        
        result = ((r1 || r2) && r3);
    }
    return result;
}

int main()
{
    {
        string s = "0";
        cout << s << " : " << (isNumber(s) ? "Y" : "N") << endl;
    }
    
    {
        string s = ".1";
        cout << s << " : " << (isNumber(s) ? "Y" : "N") << endl;
    }
    
    {
        string s = "2e0";
        cout << s << " : " << (isNumber(s) ? "Y" : "N") << endl;
    }
    
    return 0;
}