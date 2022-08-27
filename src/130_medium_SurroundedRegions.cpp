/*
    Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
    A region is captured by flipping all 'O's into 'X's in that surrounded region.

    Example 1:
        Input: board = [
            ["X","X","X","X"],
            ["X","O","O","X"],
            ["X","X","O","X"],
            ["X","O","X","X"]]
            
        Output: [
            ["X","X","X","X"],
            ["X","X","X","X"],
            ["X","X","X","X"],
            ["X","O","X","X"]]
        
    Explanation: Notice that an 'O' should not be flipped if:
    - It is on the border, or
    - It is adjacent to an 'O' that should not be flipped.
    The bottom 'O' is on the border, so it is not flipped.
    The other three 'O' form a surrounded region, so they are flipped.
    
    Example 2:
        Input: board = [["X"]]
        Output: [["X"]]
*/

#include <vector>
#include <iostream>
using namespace std;

template <class T> 
void printVector2D(const vector<vector<T>>& board)
{
    for (auto& vec: board) {
        for (const T& ch : vec) cout << ch << ' ';
        cout << endl;
    }
    cout << "----------------\n";
}

const int X = 1;
const int O = 0;
const int FIXED_O = -1; 
    
void iterMark(vector<vector<int>>& visited, vector<vector<int>>& flagBoard, 
    const int rows, const int cols, int i, int j)
{
    if (flagBoard[i][j] != FIXED_O) return;
    if (visited[i][j] == 1) return; 
    
    if (i-1 >= 0 && flagBoard[i-1][j] == O) {
        // cout << "In " << i << "," << j << " - mark: " << i-1 << ", " << j << endl;
        flagBoard[i-1][j] = FIXED_O; 
        iterMark(visited, flagBoard, rows, cols, i-1, j);
    }
    
    if (i+1 < rows && flagBoard[i+1][j] == O) {
        // cout << "In " << i << "," << j << " - mark: " << i+1 << ", " << j << endl;
        flagBoard[i+1][j] = FIXED_O;
        iterMark(visited, flagBoard, rows, cols, i+1, j);
    }
    
    if (j-1 >= 0 && flagBoard[i][j-1] == O) {
        // cout << "In " << i << "," << j << " - mark: " << i << ", " << j-1 << endl;
        flagBoard[i][j-1] = FIXED_O;
        iterMark(visited, flagBoard, rows, cols, i, j-1);
    }
    
    if (j+1 < cols && flagBoard[i][j+1] == O) {
        // cout << "In " << i << "," << j << " - mark: " << i << ", " << j+1 << endl;
        flagBoard[i][j+1] = FIXED_O;
        iterMark(visited, flagBoard, rows, cols, i, j+1);
    }
    
    visited[i][j] = 1;
}

void solve(vector<vector<char>>& board)
{
    int rows = board.size();
    if (rows <= 1) return;
    
    int cols = board[0].size();
    if (cols <= 1) return;
    
    vector<vector<int>> visited;
    for (int i=0; i<rows; i++) {
        vector<int> line(cols, 0);
        for (int j=0; j<cols; j++) {
            if (board[i][j] == 'X') line[j] = 1;
        }
        visited.push_back(line);
    }
    // printVector2D(visited);
    
    vector<vector<int>> flagBoard;
    for (int i=0; i<rows; i++) {
        vector<int> line(cols, 0); 
        for (int j=0; j<cols; j++) {
            if (board[i][j] == 'X') line[j] = X;
            else {
                if (i==0 || j==0 || i==rows-1 || j==cols-1) line[j] = FIXED_O;
                else line[j] = O;
            }
        }
        flagBoard.push_back(line);
    }
    // printVector2D(flagBoard);
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (!visited[i][j] && flagBoard[i][j] == FIXED_O) {
                iterMark(visited, flagBoard, rows, cols, i, j);
            }
        }
    }
    
    // All the FIXED_O has been marked, the rest O should be converted to X
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (flagBoard[i][j] == O) board[i][j] = 'X';
        }
    }
}

int main()
{
    vector<vector<char>> board;

    board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    
    printVector2D(board);
    solve(board);
    printVector2D(board);
    
    board = {
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'}, 
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'}
    };

    printVector2D(board);
    solve(board);
    printVector2D(board);

    return 0;
}
