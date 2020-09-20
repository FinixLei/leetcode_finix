/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;


string countAndSay(int n) 
{
    if (n <= 0 || n > 50) return "";
    if (n == 1) return "1"; 
    
    // pair.first is number, pair.second is quantity 
    vector<string> result {"0", "1"};

    vector< vector<pair<int, int>> > result_pairs; 
    
    vector<pair<int, int>> nq0 {};
    vector<pair<int, int>> nq1 {make_pair(1, 1)};
    result_pairs.push_back(nq0);
    result_pairs.push_back(nq1);
    
    int index = 2;
    while (index <= n) 
    {
        string tmp = "";
        
        // Generate result[index] per result_pairs[index-1]
        for ( auto p : result_pairs[index-1] ) {
            char q = (p.second <= 0 || p.second > 9) ? 0 : p.second + '0'; 
            char n = (p.first  <= 0 || p.first  > 9) ? 0 : p.first  + '0'; 
            tmp.push_back(q);
            tmp.push_back(n);
        }
        result.push_back(tmp);
        
        if (index == n) break; 
        
        // Generate result_pairs[index]
        vector< pair<int, int> > vec_pair; 
        int i = 0;
        int size = tmp.size();
        while (i < size) {
            int count = 1; 
            if (i+1 < size) {
                while (i+1 < size && tmp[i] == tmp[i+1]) {
                    ++ i;
                    ++ count;
                }
                vec_pair.push_back(make_pair(tmp[i]-'0', count));
            }
            else {  // i+1 == size
                vec_pair.push_back(make_pair(tmp[i]-'0', count));
            }
            ++ i; 
        }
        result_pairs.push_back(vec_pair);
        
        index ++;
    }
    
    return result[n];
}

int main()
{
    string result = "";
    
    result = countAndSay(2);
    cout << "result is " << result << endl;
    
    result = countAndSay(3);
    cout << "result is " << result << endl;
    
    result = countAndSay(4);
    cout << "result is " << result << endl;
    
    result = countAndSay(5);
    cout << "result is " << result << endl;
    
    result = countAndSay(6);
    cout << "result is " << result << endl;

    return 0;
}
