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
#include <climits>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    
    vector<int> vec;
    int t = x;
    while (t > 0) {
        vec.push_back(t%10);
        t /= 10;
    }
    
    unsigned long num = 0;
    for (auto i : vec) {
        num = num * 10 + i;
        if (num > INT_MAX) return false;
    }
    return num == x; 
}
