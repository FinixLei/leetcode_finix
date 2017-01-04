#include <iostream>
using namespace std;


bool isValid(string s) {
    const char * str = s.c_str();    
    char * stack = new char[s.length()+1];
    int count = 0;
    bool result = true;
    
    while (*str != 0x0) {
        if (*str == '(' || *str == '[' || *str == '{') {
            stack[count++] = *str;
        }
        else if (*str == ')') {
            if (count == 0 || stack[count-1] != '(') {
                result = false;
                break;
            }
            else {
                -- count;
            }
        }
        else if (*str == ']') {
            if (count == 0 || stack[count-1] != '[') {
                result = false;
                break;
            }
            else {
                -- count;
            }
        }
        else if (*str == '}') {
            if (count == 0 || stack[count-1] != '{') {
                result = false;
                break;
            }
            else {
                -- count;
            }
        }
        
        ++ str;
    }
    
    delete [] stack;
    if (count > 0) result = false;
    
    return result;
}


int main()
{
    string s1 = "(abc)de[gz]{890}";
    string s2 = "abc[(ab)]";
    string s3 = "([])";
    string s4 = "(}{)";
    string s5 = "][";
    string s6 = "([)]";
    
    cout << s1 << " is " << (isValid(s1) ? "valid" : "invalid") << endl;
    cout << s2 << " is " << (isValid(s2) ? "valid" : "invalid") << endl;
    cout << s3 << " is " << (isValid(s3) ? "valid" : "invalid") << endl;
    cout << s4 << " is " << (isValid(s4) ? "valid" : "invalid") << endl;
    cout << s5 << " is " << (isValid(s5) ? "valid" : "invalid") << endl;
    cout << s6 << " is " << (isValid(s6) ? "valid" : "invalid") << endl;
    
    return 0;
}