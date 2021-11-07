#include <climits>
#include <iostream>
using namespace std;


int mySqrt(int x) 
{
    if (x == 0) return 0;
    if (x <= 3) return 1;
    
    long  ul_x = (unsigned long)x; 
    long min_num = 0;
    long max_num = ul_x; 
    long result = x/2; 
    
    while (true) {
        long r1 = result * result; 
        long r2 = (result+1) * (result+1);
        
        if (r1 <= ul_x && r2 > ul_x) break; 

        if (r1 > ul_x) {
            max_num = result; 
        }
        else {    // r1 < ul_x 
            min_num = result;
        }
        result = min_num + (max_num-min_num)/2; 
    }
    
    return (int)result; 
}


int main()
{
    cout << "sqrt of " << 4 << " is " << mySqrt(4) << endl; 
    cout << "sqrt of " << 8 << " is " << mySqrt(8) << endl; 
    cout << "sqrt of " << 9 << " is " << mySqrt(9) << endl; 
    cout << "sqrt of " << 15 << " is " << mySqrt(15) << endl; 
    cout << "sqrt of " << 235 << " is " << mySqrt(235) << endl; 
    
    cout << "sqrt of " << 8192 << " is " << mySqrt(8192) << endl; 
    cout << "sqrt of " << INT_MAX << " is " << mySqrt(INT_MAX) << endl; 
    cout << "sqrt of " << 2147395599 << " is " << mySqrt(2147395599) << endl; 
    
    return 0;
}