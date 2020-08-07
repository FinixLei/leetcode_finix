/*
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

    Example 1:

    Input: "III"
    Output: 3
    Example 2:

    Input: "IV"
    Output: 4
    Example 3:

    Input: "IX"
    Output: 9
    Example 4:

    Input: "LVIII"
    Output: 58
    Explanation: L = 50, V= 5, III = 3.
    Example 5:

    Input: "MCMXCIV"
    Output: 1994
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/


#include <iostream>
#include <string>
using namespace std;

// I V X L C D M 

int romanToInt(string s) {
    int result = 0;
    int size = s.size();
    int pos = 0;
    
    while (pos < size) {
        if (s[pos] == 'M') {
            result += 1000;
            pos ++;
        }
        else if (s[pos] == 'D') {
            result += 500;
            pos ++;
        }
        else if (s[pos] == 'L') {
            result += 50;
            pos ++;
        }
        else if (s[pos] == 'V') {
            result += 5;
            pos ++;
        }
        else if (s[pos] == 'I') {
            if (pos + 1 < size) {
                if (s[pos+1] == 'V') {
                    result += 4;
                    pos += 2;
                }
                else if (s[pos+1] == 'X') {
                    result += 9;
                    pos += 2;
                }
                else {
                    result += 1;
                    pos ++;
                }
            }
            else {
                result += 1;
                break;
            }
        }
        else if (s[pos] == 'X') {
            if (pos + 1 < size) {
                if (s[pos+1] == 'L') {
                    result += 40;
                    pos += 2;
                }
                else if (s[pos+1] == 'C') {
                    result += 90;
                    pos += 2;
                }
                else {
                    result += 10;
                    pos ++;
                }
            }
            else {
                result += 10;
                break;
            }
        }
        else if (s[pos] == 'C') {
            if (pos + 1 < size) {
                if (s[pos+1] == 'D') {
                    result += 400;
                    pos += 2;
                }
                else if (s[pos+1] == 'M') {
                    result += 900;
                    pos += 2;
                }
                else {
                    result += 100;
                    pos ++;
                }
            }
            else {
                result += 100;
                break;
            }
        }
        else {
            // do nothing, never hit here
        }
    }
    
    return result;
}

int main()
{
    string s = "";
    int result = 0;
    
    s = "MCMXCIV";
    result = romanToInt(s); 
    cout << s << " = " << result << endl;
    
    return 0;
}
