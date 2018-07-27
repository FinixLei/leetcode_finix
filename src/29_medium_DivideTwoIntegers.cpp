/*Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        long a = dividend;
        long b = divisor;
        long d1 = a >= 0? a:-a;
        long d2 = b > 0? b:-b;
        
        if (d1 < d2) {
            result = 0;
        }
        if (d1 == d2) {
            if ((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) 
                result = 1;
            else
                result = -1;
        }
        if (d1 > d2) {
            if ((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) {
                int m = d1 % d2;
                result = (d1-m)/d2;
            }
            if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) {
                int m = d1 % d2;
                result = -(d1-m)/d2;
            }
        }
        
   
        if ((dividend<0 && divisor<0 && result<0) || (dividend>0 && divisor>0 && result<0) ||
            (dividend>0 && divisor<0 && result>0) || (dividend<0 && divisor>0 && result>0)) {
            return 2147483647;
        }
        return result;
    }

};