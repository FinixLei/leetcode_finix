/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

void search(vector<vector<string>>& result, 
            vector<int>& columns, 
            vector<int>& records, 
            int row, int col, const int n)
{
    if (row == n) {
        vector<string> one_result;
        for (int r=0; r<n; r++) {
            string line(n, '.');
            line[records[r]] = 'Q';
            one_result.push_back(line);
        }
        result.push_back(one_result);
        return;
    }

    while (col < n) {
        if (columns[col] == 1) {col ++; continue; }
        if (row > 0) {
            int k = 1;
            bool hit = false;
            while (k <= row) {
                if (records[row-k] == col-k || records[row-k] == col+k) {
                    hit = true; 
                    break;
                }
                k++;
            }
            if (hit) { col ++; continue; }
        }
        
        columns[col] = 1;
        records[row] = col;
        search(result, columns, records, row+1, 0, n);  
        columns[col++] = 0;
        records[row] = -1;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<int> columns(n, 0);
    vector<int> records(n, -1);
    search(result, columns, records, 0, 0, n);
    return result;
}

int main()
{
    int n;
    cout << "Input n: "; 
    cin >> n;
    
    vector<vector<string>> result = solveNQueens(n);
    
    for (auto vec : result) {
        for (auto str : vec) {
            cout << str << endl;
        }
        cout << endl;
    }
    cout << "size is " << result.size() << endl;
    
    return 0;
}
