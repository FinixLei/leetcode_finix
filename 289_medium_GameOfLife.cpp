/*
    According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

    Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    Write a function to compute the next state (after one update) of the board given its current state.
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.back().size();
        vector< vector<int> > copy_board = board;
    
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int live_num = 0;
                
                // direction-1
                if (i-1 >= 0 && j-1 >= 0) {
                    if (board[i-1][j-1] == 1) live_num ++;
                }
                
                // direction-2
                if (i-1 >= 0) {
                    if (board[i-1][j] == 1) live_num ++;
                }
                
                // direction-3
                if (i-1 >= 0 && j+1 <= n-1) {
                    if (board[i-1][j+1] == 1) live_num ++;
                }
                
                // direction-4
                if (j-1 >= 0) {
                    if (board[i][j-1] == 1) live_num ++;
                }
                
                // direction-5
                if (j+1 <= n-1) {
                    if (board[i][j+1] == 1) live_num ++;
                }
                
                // direction-6
                if (i+1 <= m-1 && j-1 >= 0) {
                    if (board[i+1][j-1] == 1) live_num ++;
                }
                
                // direction-7
                if (i+1 <= m-1) {
                    if (board[i+1][j] == 1) live_num ++;
                }
                
                // direction-8
                if (i+1 <= m-1 && j+1 <= n-1) {
                    if (board[i+1][j+1] == 1) live_num ++;
                }
                
                // Rules
                if (board[i][j] == 1) {
                    if (live_num < 2 || live_num > 3) copy_board[i][j] = 0;
                } else {  // board[i][j] == 0
                    if (live_num == 3) copy_board[i][j] = 1;
                }
            }
        }
        
        for (int i=0; i<m; i++) 
            for (int j=0; j<n; j++)
                board[i][j] = copy_board[i][j];
    }
};
