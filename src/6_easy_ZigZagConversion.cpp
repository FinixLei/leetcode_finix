#include <cstring>
#include <iostream>
using namespace std;

/*
    A   I   Q
    B  HJ  PR
    C G K O S
    DF  LN  T
    E   M

    AIQBHJPRCGKOSDFLNTEM
*/

string convert(string s, int numRows) {
    const int size = s.size();
    if (numRows <= 1 || numRows >= size) return s;
    
    char new_array[numRows][size+1];
    memset(&new_array[0][0], 0, sizeof(new_array));
    
    int pos[numRows]; 
    memset(&pos[0], 0, sizeof(pos));

    int row = 0;
    int step = 1;
    for (int i=0; i<size; i++) {
        if (row == numRows-1) step = -1;
        if (row == 0) step = 1;
        
        new_array[row][pos[row]] = s[i];
        pos[row] ++;
        row += step;
    }
    
    string result = "";
    for (int i=0; i<numRows; i++) {
        result += string(new_array[i]);
    }
    
    return result;
}


int main() {
    cout << convert("PAYPALISHIRING", 3) << endl;
    cout << convert("", 1) << endl;
    cout << convert("AB", 1) << endl;
    cout << convert("ABC", 1) << endl;
    cout << convert("ABC", 2) << endl;
    cout << convert("ABCDEFGHIJKLMNOPQRST", 5) << endl;
    return 0;
}
