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
    Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

    Example 1:

    Input: 3
    Output: "III"
    Example 2:

    Input: 4
    Output: "IV"
    Example 3:

    Input: 9
    Output: "IX"
    Example 4:

    Input: 58
    Output: "LVIII"
    Explanation: L = 50, V = 5, III = 3.
    Example 5:

    Input: 1994
    Output: "MCMXCIV"
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


string intToRoman(int num) 
{
    char buf[20];
    memset(buf, 0, 20);
    
    int t = num / 1000 * 1000;
    int h = (num - t) / 100 * 100; 
    int x = (num - t - h) / 10 * 10;
    int u = num % 10; 
    
    int pos = 0;
    for (int i=0; i<t/1000; i++) {
        buf[pos++] = 'M';
    }
    
    switch (h) {
    case 100:
        strncpy(buf+pos, "C", 1);
        pos += 1;
        break;
        
    case 200:
        strncpy(buf+pos, "CC", 2);
        pos += 2;
        break;
        
    case 300:
        strncpy(buf+pos, "CCC", 3);
        pos += 3;
        break;
        
    case 400: 
        strncpy(buf+pos, "CD", 2);
        pos += 2;
        break;
        
    case 500: 
        strncpy(buf+pos, "D", 1);
        pos += 1;
        break;
        
    case 600: 
        strncpy(buf+pos, "DC", 2);
        pos += 2;
        break;
        
    case 700: 
        strncpy(buf+pos, "DCC", 3);
        pos += 3;
        break;
        
    case 800: 
        strncpy(buf+pos, "DCCC", 4);
        pos += 4;
        break;
        
    case 900: 
        strncpy(buf+pos, "CM", 2);
        pos += 2;
        break;
    }
    
    switch (x) {
    case 10:
        strncpy(buf+pos, "X", 1);
        pos += 1;
        break;
        
    case 20:
        strncpy(buf+pos, "XX", 2);
        pos += 2;
        break;
        
    case 30:
        strncpy(buf+pos, "XXX", 3);
        pos += 3;
        break;
        
    case 40: 
        strncpy(buf+pos, "XL", 2);
        pos += 2;
        break;
        
    case 50: 
        strncpy(buf+pos, "L", 1);
        pos += 1;
        break;
        
    case 60: 
        strncpy(buf+pos, "LX", 2);
        pos += 2;
        break;
        
    case 70: 
        strncpy(buf+pos, "LXX", 3);
        pos += 3;
        break;
        
    case 80: 
        strncpy(buf+pos, "LXXX", 4);
        pos += 4;
        break;
        
    case 90: 
        strncpy(buf+pos, "XC", 2);
        pos += 2;
        break;
    }
    
    switch (u) {
    case 1:
        strncpy(buf+pos, "I", 1);
        pos += 1;
        break;
        
    case 2:
        strncpy(buf+pos, "II", 2);
        pos += 2;
        break;
        
    case 3:
        strncpy(buf+pos, "III", 3);
        pos += 3;
        break;
        
    case 4: 
        strncpy(buf+pos, "IV", 2);
        pos += 2;
        break;
        
    case 5: 
        strncpy(buf+pos, "V", 1);
        pos += 1;
        break;
        
    case 6: 
        strncpy(buf+pos, "VI", 2);
        pos += 2;
        break;
        
    case 7: 
        strncpy(buf+pos, "VII", 3);
        pos += 3;
        break;
        
    case 8: 
        strncpy(buf+pos, "VIII", 4);
        pos += 4;
        break;
        
    case 9: 
        strncpy(buf+pos, "IX", 2);
        pos += 2;
        break;
    }
    
    return string(buf);
}

int main()
{
    int num = 0;
    string result = "";
    
    num = 1994; 
    result = intToRoman(num);
    cout << num << " => " << result << endl;

    return 0;
}