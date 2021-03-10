#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) 
{
    if ( n == 0 || n == 1 || n == 2 ) return n;
    
    int p1 = 1, p2 = 2, result = 0;
    
    for (int i = 3; i <= n; i++) {
        result = p1 + p2; 
        p1 = p2; 
        p2 = result; 
    }
    
    return result; 
}


int main()
{
    int n = 0;
    
    n = 3;
    cout << n << ": " << climbStairs(n) << endl;
    
    n = 4;
    cout << n << ": " << climbStairs(n) << endl;
    
    n = 5;
    cout << n << ": " << climbStairs(n) << endl;
    
    return 0;
}