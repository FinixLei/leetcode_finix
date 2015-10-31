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
using namespace std;

int myAtoi(string str) {
    // Step 1: remove whitespaces
    int i;
    for (i = 0; i < str.size(); ) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') {
            i++;
        }
        else {
            break;
        }
    }
    str = string(&str[i]); 
    if (str.size() == 0) return 0;

    // Step 2: record sign
    bool isPositive = true;
    if (str[0] == '+') {
        str = string(&str[1]);
    } 
    else if (str[0] == '-') {
        isPositive = false;
        str = string(&str[1]);
    }
    
    // Step 3: collect numbers
    string pure_num = "";
    i = 0;
    while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
        pure_num += str[i++];
    }
    if (pure_num == "") return 0;
    
    // Step 4: validate range and transformation
    int MAX = 2147483647;
    int MIN = -2147483648;

    if (pure_num.size() > 10) {
        return isPositive ? MAX: MIN;
    }

    long result = 0; 
    for (i = 0; i < pure_num.size(); i++) {
        result *= 10;
        if (result < 0 || result > MAX) return isPositive ? MAX : MIN;  // overflow
        result += pure_num[i] - '0';
        if (result < 0 || result > MAX) return isPositive ? MAX : MIN;  // overflow
    }

    return isPositive ? (int)result : (int)-result;
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
