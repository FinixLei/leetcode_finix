/*
Implement atoi to convert a string to an integer.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include <string>
#include <iostream>
#include <climits>
using namespace std;

int convertToInt(string& str, int pos, bool bPos) {
    long num = 0;
    while (pos < str.size()) {
        int n = str[pos]-'0';
        if (n < 0 || n > 9) break;
        
        num = num * 10 + n;
        if (num > INT_MAX) break;
        pos ++;
    }
    num = bPos ? num : -num;
    
    return num > INT_MAX ? INT_MAX : (num <= INT_MIN ? INT_MIN : num);
}

int myAtoi(string str) {
    int size = str.size();
    int i=0;
    while (i < size) {
        if (str[i] == ' ') i++;
        else break;
    }
    if (i == size) return 0;
    
    bool bPos = true;
    if (str[i] == '+') {
        i++;
    }
    else if (str[i] == '-') {
        bPos = false;
        i++;
    }
    
    int result = convertToInt(str, i, bPos);
    return result;
}

int main() {
    cout << myAtoi("   123") << endl;
    cout << myAtoi("   +34123") << endl;
    cout << myAtoi("   -123") << endl;
    cout << myAtoi("   0") << endl;
    cout << myAtoi("   +0") << endl;
    cout << myAtoi("   -0") << endl;
    cout << myAtoi("   abc123") << endl;
    cout << myAtoi("   567abc") << endl;
    cout << myAtoi("1234567891") << endl;
    cout << myAtoi("12345678999") << endl;
    cout << myAtoi("2147483648") << endl;
     
    return 0;
}
