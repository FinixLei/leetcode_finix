/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31−1]
*/

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if (n==0) return 1;
    if (x==0) return 0;
    if (x==1) return 1;
    if (x==-1) {
        if (n>0) {
            if (n%2 == 0) return 1;
            else return -1;
        }
        else {  // n < 0
            if (n==-2147483648) return 1;
            if ((-n)%2 == 0) return 1;
            else return -1;
        }
    }
    if (n==-2147483648) return 0;
   
    bool pos_x = x>0 ? true : false;
    bool pos_n = n>0 ? true : false;
    bool overflow = false; 
    
    if (!pos_x) x = -x;
    if (!pos_n) n = -n;
    
    double result = 1;
    for (int i=0; i<n; i++) {
        result *= x; 
        if (result <= 0) {
            overflow = true;
            break;
        }
    }
    
    if (overflow) {
        return 0;
    }
    
    if (!pos_x && n%2 == 1) result = -result;    
    return pos_n ? result : 1/result; 
}

int main()
{
    double result = 0;
    
    result = myPow(2, 10);
    cout << "myPow(2, 10) = " << result << endl;
    
    result = myPow(-1, -2147483648);
    cout << "myPow(-1, -2147483648) = " << result << endl;
    
    result = myPow(2, -2147483648);
    cout << "myPow(2, -2147483648) = " << result << endl;

    return 0;
}
