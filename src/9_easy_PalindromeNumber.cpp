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
    while (x > 0) {
        vec.push_back(x%10);
        x /= 10;
    }
    
    int i=0, j=vec.size()-1;
    while (i<j) {
        if (vec[i++] != vec[j--]) return false;
    }
    return true;
}
