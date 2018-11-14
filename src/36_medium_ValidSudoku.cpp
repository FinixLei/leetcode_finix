/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/


#include <vector>
#include <cstring>
#include <iostream>
using namespace std;


class Solution {
private:
    bool check_redundant(vector<char> vec)
    {
        int records[9] = {0,0,0,0,0,0,0,0,0};
        
        for (auto ch: vec) {
            if (ch == '.') continue;
            int tmp = ch-'0';
            if (records[tmp-1] == 0) 
                records[tmp-1] = 1;
            else 
                return false;
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check every row
        for (int i=0; i<9; ++i) {
            if (check_redundant(board[i]) == false) {
                return false;
            }
        }

        // check every column
        for (int i=0; i<9; ++i) {
            vector<char> column;
            for (int j=0; j<9; ++j) {
                column.push_back(board[j][i]);
            }
            if (check_redundant(column) == false) {
                return false;
            }
        }

        // check every block
        pair<int, int> blocks[9][9] = {
            {{0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}},
            {{0,3}, {0,4}, {0,5}, {1,3}, {1,4}, {1,5}, {2,3}, {2,4}, {2,5}},
            {{0,6}, {0,7}, {0,8}, {1,6}, {1,7}, {1,8}, {2,6}, {2,7}, {2,8}},
            {{3,0}, {3,1}, {3,2}, {4,0}, {4,1}, {4,2}, {5,0}, {5,1}, {5,2}},
            {{3,3}, {3,4}, {3,5}, {4,3}, {4,4}, {4,5}, {5,3}, {5,4}, {5,5}},
            {{3,6}, {3,7}, {3,8}, {4,6}, {4,7}, {4,8}, {5,6}, {5,7}, {5,8}},
            {{6,0}, {6,1}, {6,2}, {7,0}, {7,1}, {7,2}, {8,0}, {8,1}, {8,2}},
            {{6,3}, {6,4}, {6,5}, {7,3}, {7,4}, {7,5}, {8,3}, {8,4}, {8,5}},
            {{6,6}, {6,7}, {6,8}, {7,6}, {7,7}, {7,8}, {8,6}, {8,7}, {8,8}},
        };

        for (int i=0; i<9; ++i) {
            vector<char> tmp;
            tmp.reserve(9);  // size is still 0
            for (int j=0; j<9; ++j) {
                tmp.push_back(board[blocks[i][j].first][blocks[i][j].second]);
            }
            
            if (check_redundant(tmp) == false) {
                return false;
            }
        }

        // finally
        return true;
    }
    
    void test() 
    {
        char arrays[9][9] = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        
        vector<vector<char>> board(9);
        for (int i=0; i<9; ++i) {
            board[i].insert(board[i].begin(), arrays[i], arrays[i]+9);
        }
        
        bool result = isValidSudoku(board);
        if (result) {
            cout << "It is Sudoku!" << endl;
        }
        else {
            cout << "It is not a Sudoku!" << endl;
        }
    }
};

int main()
{
    Solution s;
    s.test();
    
    return 0;
}