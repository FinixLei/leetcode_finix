/*
    Write a program to check whether a given number is an ugly number.

    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

    Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
    bool isUgly(int num) {
        if (num == 1) {
            return true;
        }
            
        if (num <= 0) {
            return false;
        }
        
        int result = num;
        while (result % 2 == 0) {
            result /= 2;
        }
        while (result % 3 == 0) {
            result /= 3;
        }
        while (result % 5 == 0) {
            result /= 5;
        }
        
        if (result == 1) {
            return true;
        } else {
            return false;
        }
    }
};
