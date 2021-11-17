/*
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

Example 1:
    Input: n = 2
    Output: [0,1,3,2]
    Explanation:
        The binary representation of [0,1,3,2] is [00,01,11,10].
        - 00 and 01 differ by one bit
        - 01 and 11 differ by one bit
        - 11 and 10 differ by one bit
        - 10 and 00 differ by one bit
        [0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
        - 00 and 10 differ by one bit
        - 10 and 11 differ by one bit
        - 11 and 01 differ by one bit
        - 01 and 00 differ by one bit
        
Example 2:
    Input: n = 1
    Output: [0,1]
    
Constraints:
    1 <= n <= 16
*/

class Solution {
public:
    constexpr static const int table[17] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
                                         // 0, 1, 2, 3, 4,  5,  6,  7,   8,   9,   10,   11,   12,   13,   14,    15,    16
    
    void printVec(vector<int>& vec) {
        for (auto i : vec) cout << i << " ";
        cout << endl;
    }
    
    int genNum(const vector<char>& binary) {
        int result = 0;
        for (int i=0; i<binary.size(); i++) {
            if (binary[i] == 0) continue;
            result += table[i]; 
        }
        return result; 
    }
    
    vector<int> grayCode(int n) {     
        vector<int> visited(table[n], 0);        
        vector<char> binary(n, 0);        
        vector<int> result{0}; 
        visited[0] = 1;
        
        for (int pos=0; pos<n; ) {
            binary[pos] = 1-binary[pos];
            int num = genNum(binary);
            
            if ( visited[num] == 0 ) {
                result.push_back(num);
                if (result.size() == table[n]) break;
                visited[num] = 1;
                pos = pos > 0 ? 0 : 1;
            }
            else {   // if it has been visited, roll back and increase pos. 
                binary[pos] = 1-binary[pos];
                pos ++;
                if (pos == n) pos = 0;
            }
        } 
        
        // printVec(result);
        return result;
    }
};