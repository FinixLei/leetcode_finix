/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/


#include <vector>
#include <string>
#include <iostream>
using namespace std;


string multiply(string num1, string num2) {
    if (num1=="0" || num2=="0") return "0";
    
    int s1 = num1.size();
    int s2 = num2.size();
    int size = s1+s2-1; 
    vector<int> vec(size, 0);
    
    for (int i=0; i<s1; i++) {
        for (int j=0; j<s2; j++) {
            vec[i+j] += (num1[i]-'0') * (num2[j]-'0');
        }
    }
    
    vector<char> vc; 
    int num=0, n=0, c=0; // n是当前位数字，c是进位
    for (int i=size-1; i>=0; i--) {
        int num = vec[i] + c; 
        int n = num % 10;
        c = num / 10;
        vc.push_back('0'+n);
    }
    if (c>0) vc.push_back('0'+c);
    
    int vc_size = vc.size();
    for (int i=0; i<=(vc_size-1)/2; i++) {
        swap(vc[i], vc[vc_size-1-i]);
    }
    
    string result(vc.begin(), vc.end());
    return result;
}


int main()
{
    string result = multiply("123", "456");
    cout << "result = " << result << endl;
    
    return 0;
}