/*
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
    Input: s = "25525511135"
    Output: ["255.255.11.135","255.255.111.35"]

Example 2:
    Input: s = "0000"
    Output: ["0.0.0.0"]

Example 3:
    Input: s = "101023"
    Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_vec_str(vector<string>& vec) {
    for (auto s : vec) cout << s << " ";
    cout << endl;
}

bool validNumber(const string & s, const int start, const int count) {
    if (count > 3 || count < 1) return false;
    if (start < 0 || start >= s.size()) return false;
    if (count > 1 && s[start] == '0') return false;
    
    int num = 0;
    for (int i=0; i<count; i++) {
        num = num * 10 + s[start+i] - '0';
    }
    
    if ( num >=0 && num <= 255) return true;
    return false;
}

// section can only be 1, 2, 3, 4
void helper(const string& s, const int start, int section, string& currStr, vector<string>& result)
{
    if (section >= 4) {
        int count = s.size() - start;
        if (count > 3) return;
       
        if (validNumber(s, start, count)) {
            currStr.push_back('.');
            for (int i=0; i<count; i++) currStr.push_back(s[start+i]);
            result.push_back(currStr);
        }
        return;
    }
    
    if (section > 1) currStr.push_back('.');
    
    // section = 1, 2, 3
    // count means string length in current section
    for (int count=1; count<=3; count++) {
        string tmp = currStr; 
        if (validNumber(s, start, count)) {
            for (int i=0; i<count; i++) {
                tmp.push_back(s[start+i]);
            }
            helper(s, start+count, section+1, tmp, result);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    int len = s.size();
    if (len < 4 || len > 12) return {};
    
    vector<string> result;
    string currStr = "";
    helper(s, 0, 1, currStr, result);
    return result;
}

int main()
{
    vector<string> result;
    result = restoreIpAddresses("25525511135");
    print_vec_str(result);
    
    return 0;
}