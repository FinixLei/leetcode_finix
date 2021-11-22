/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. 
How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) {
    if (x == 0 || x == INT_MIN) return 0;
    
    bool bPos = ( x > 0 ); 
    if (!bPos ) x=-x;
    
    unsigned long result = 0;
    while (x>0) {
        result = result *10 + x%10;
        if (result > INT_MAX) return 0;
        x /= 10; 
    }
    return bPos ? result : (-result);
}

int main() {
    cout << reverse(0) << endl;
    cout << reverse(1000) << endl;
    cout << reverse(654) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(1000000003) << endl;
    cout << reverse(1534236469) << endl;

    return 0;
}