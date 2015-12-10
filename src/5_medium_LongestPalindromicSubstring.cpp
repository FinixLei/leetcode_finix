/*
    Given a string S, find the longest palindromic substring in S. 
    You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include <cstring>
#include <iostream>
using namespace std;


string longestPalindrome(string s) {
    char result[1024];
    char array[1024];
    strcpy(array, s.c_str()); 
    
    int size = s.size();    
    int length = 0;
    
    for (int i=0; i<size; i++) {
        for (int j=length+1; j<=size-i; j++) {
            int k = 0;
            while (k <= j-1-k) {
                if (array[i+k] != array[i+j-1-k]) break;
                k++;
            }
            if (k > j-1-k) {
                length = j;
                strncpy(result, &array[i], length); 
                result[length] = '\0';
            }
        }
    }
    
    return result;
}

int main()
{
    cout << longestPalindrome("abadd") << endl;
}