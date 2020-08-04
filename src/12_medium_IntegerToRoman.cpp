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
#include <unordered_map>
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
    
    switch (t) {
    case 1000:
        strcpy(buf, "M");
        pos += 1;
        break;
        
    case 2000:
        strcpy(buf, "MM");
        pos += 2;
        break;
        
    case 3000:
        strcpy(buf, "MMM");
        pos += 3;
    }

    switch (h) {
    case 100:
        strcpy(buf+pos, "C");
        pos += 1;
        break;
        
    case 200:
        strcpy(buf+pos, "CC");
        pos += 2;
        break;
        
    case 300:
        strcpy(buf+pos, "CCC");
        pos += 3;
        break;
        
    case 400: 
        strcpy(buf+pos, "CD");
        pos += 2;
        break;
        
    case 500: 
        strcpy(buf+pos, "D");
        pos += 1;
        break;
        
    case 600: 
        strcpy(buf+pos, "DC");
        pos += 2;
        break;
        
    case 700: 
        strcpy(buf+pos, "DCC");
        pos += 3;
        break;
        
    case 800: 
        strcpy(buf+pos, "DCCC");
        pos += 4;
        break;
        
    case 900: 
        strcpy(buf+pos, "CM");
        pos += 2;
        break;
    }
    
    switch (x) {
    case 10:
        strcpy(buf+pos, "X");
        pos += 1;
        break;
        
    case 20:
        strcpy(buf+pos, "XX");
        pos += 2;
        break;
        
    case 30:
        strcpy(buf+pos, "XXX");
        pos += 3;
        break;
        
    case 40: 
        strcpy(buf+pos, "XL");
        pos += 2;
        break;
        
    case 50: 
        strcpy(buf+pos, "L");
        pos += 1;
        break;
        
    case 60: 
        strcpy(buf+pos, "LX");
        pos += 2;
        break;
        
    case 70: 
        strcpy(buf+pos, "LXX");
        pos += 3;
        break;
        
    case 80: 
        strcpy(buf+pos, "LXXX");
        pos += 4;
        break;
        
    case 90: 
        strcpy(buf+pos, "XC");
        pos += 2;
        break;
    }
    
    switch (u) {
    case 1:
        strcpy(buf+pos, "I");
        pos += 1;
        break;
        
    case 2:
        strcpy(buf+pos, "II");
        pos += 2;
        break;
        
    case 3:
        strcpy(buf+pos, "III");
        pos += 3;
        break;
        
    case 4: 
        strcpy(buf+pos, "IV");
        pos += 2;
        break;
        
    case 5: 
        strcpy(buf+pos, "V");
        pos += 1;
        break;
        
    case 6: 
        strcpy(buf+pos, "VI");
        pos += 2;
        break;
        
    case 7: 
        strcpy(buf+pos, "VII");
        pos += 3;
        break;
        
    case 8: 
        strcpy(buf+pos, "VIII");
        pos += 4;
        break;
        
    case 9: 
        strcpy(buf+pos, "IX");
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