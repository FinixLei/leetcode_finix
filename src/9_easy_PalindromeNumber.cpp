/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <vector>
#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    
    int y = x;
    vector<int> array;
    
    while (y >= 10) {
        int v = y % 10;
        array.push_back(v);
        y = (y - v) / 10;
    }
    array.push_back(y);
    
    int z = 0;
    for (auto it=array.begin(); it!=array.end(); it++) {
        z = z * 10 + *it;
    }
    
    return x == z; 
}
