/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101" 
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T> 
void print_vec(const vector<T> & vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

string addBinary(string& a, string& b) 
{
    int a_size = a.size();
    int b_size = b.size();
    
    if (a_size == 0 && b_size == 0) return "";
    if (a_size == 0 && b_size != 0) return b; 
    if (a_size != 0 && b_size == 0) return a; 
    
    int short_size = min(a_size, b_size);
    int long_size = max(a_size, b_size);
    
    vector<int> va, vb, vc;
    va.reserve(a_size);
    vb.reserve(b_size);
    vc.reserve(long_size+1);
    
    for (int i=a_size-1; i>=0; i--) {
        va.push_back(a[i]-'0');
    }
    for (int i=b_size-1; i>=0; i--) {
        vb.push_back(b[i]-'0');
    }
    
    int inc = 0;
    for (int i=0; i<short_size; i++) {
        int tmp = va[i] + vb[i] + inc; 
        if (tmp <= 1) {
            vc.push_back(tmp);
            inc = 0;
        }
        else {
            vc.push_back((tmp == 2 ? 0 : 1));
            inc = 1;
        }
    }
    
    vector<int> *pv = ( a_size == long_size ? (&va) : (&vb) );

    for (int i=short_size; i<long_size; i++) {
        int tmp = inc + (*pv)[i];
        if (tmp <= 1) {
            vc.push_back(tmp);
            inc = 0;
        }
        else {
            vc.push_back( (tmp == 2 ? 0 : 1) );
            inc = 1;
        }
    }
    
    if (inc == 1) vc.push_back(1);
    
    string c; 
    int c_size = vc.size();
    for (int i=c_size-1; i>=0; i--) {
        c.push_back( (vc[i] == 0 ? '0' : '1') );
    }
    
    return c;
}

int main() 
{
    string a = "11";
    string b = "1";
    string c = addBinary(a, b);
    cout << a << " + " << b << " = " << c << endl;
    
    a = "1010";
    b = "1011";
    c = addBinary(a, b);
    cout << a << " + " << b << " = " << c << endl;
    
    a = "1111";
    b = "1111";
    c = addBinary(a, b);
    cout << a << " + " << b << " = " << c << endl;  // 11110
    
    return 0;
}