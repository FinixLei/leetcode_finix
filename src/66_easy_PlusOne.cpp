/*
    Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
    The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
    You may assume the integer does not contain any leading zero, except the number 0 itself.

    Example 1:
    Input: digits = [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.

    Example 2:
    Input: digits = [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: The array represents the integer 4321.
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


template <typename T>
void print_vector(vector<T>& vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

vector<int> plusOne(vector<int>& digits) 
{
    int dsize = digits.size();
    
    vector<int> result(dsize);
    result.reserve(dsize + 1);
    copy(digits.begin(), digits.end(), result.begin());
    
    for (int i=dsize-1; i>=0; i--) {
        int tmp = digits[i] + 1;
        if (tmp < 10) {
            result[i] = tmp;
            break;
        }
        else {
            result[i] = 0;
        }
    }
    
    if (result[0] == 0) { // last add result is 10
        result.push_back(0);
        // copy(result.begin(), result.end(), result.begin()+1);
        for (int i=dsize; i>=1; i--) {
            result[i] = result[i-1];
        }
        result[0] = 1;
    }
    
    return result;
}

int main()
{
    vector<int> vec, result;
    
    vec = {1, 2, 3};
    result = plusOne(vec);
    print_vector(result);
    
    vec = {9, 9, 9};
    result = plusOne(vec);
    print_vector(result);
    
    vec = {8, 9, 9};
    result = plusOne(vec);
    print_vector(result);
    
    vec = {9};
    result = plusOne(vec);
    print_vector(result);
    
    return 0;
}
