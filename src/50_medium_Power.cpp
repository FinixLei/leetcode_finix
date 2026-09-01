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

class Solution {
private:
    double quick_pow(double x, long N) {
        if (N == 0) return 1.0;
        if (N == 1) return x;
        if (N < 0) throw std::runtime_error("wrong parameter");

        double y = quick_pow(x, N/2);
        if (N % 2 == 0) return y*y;
        else return y*y*x;
    }

public:
    double myPow(double x, int n) {
        return n >= 0 ? quick_pow(x, n) : 1.0 / quick_pow(x, -((long)(n)));
    }
};