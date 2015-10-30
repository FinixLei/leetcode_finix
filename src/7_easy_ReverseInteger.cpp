#include <vector>
#include <iostream>
using namespace std;

int reverse(int x) {
    int max_32bit_signed_int = 2147483647;
    
    bool bMinus = false;
    if (x < 0) {
        bMinus = true;
        x = -x; 
        if (x < 0) return 0;  // overflow
    }
    
    vector<int> array;
    while (x >= 10) {
        int value = x % 10;
        array.push_back(value); 
        x = (x - value) / 10;
    }
    array.push_back(x);
    
    int size = array.size();
    long result = 0;
    for (int i=0; i<size; i++) {
        result *= 10;
        if (result > max_32bit_signed_int) return 0;
        result += array[i];
        if (result > max_32bit_signed_int) return 0;
    }
    
    int int_result = (int)result;
    return bMinus ? -int_result : int_result;
}

int main() {
    cout << reverse(0) << endl;
    cout << reverse(1000) << endl;
    cout << reverse(654) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(1000000003) << endl;
    cout << reverse(1534236469) << endl;

    return 0;
}