#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

void PrintBoard(vector<vector<char>>& board)
{
    for (auto row : board) {
        for (auto ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<char> get_avail_chars(vector<set<char>>& avail_row_sets, 
                             vector<set<char>>& avail_col_sets, 
                             vector<set<char>>& avail_blk_sets, 
                             const vector<vector<int>>& Pos2Blk, 
                             int row, 
                             int col)
{
    set<char> tmp; 
    for (char ch : avail_row_sets[row]) {
        if (avail_col_sets[col].find(ch) != avail_col_sets[col].end()) {
            tmp.insert(ch);
        }
    }
    
    vector<char> final_vec;
    int blk_id = Pos2Blk[row][col];
    for (char ch : avail_blk_sets[blk_id]) {
        if (tmp.find(ch) != tmp.end()) {
            final_vec.push_back(ch);
        }
    }
    return final_vec;
}

bool isValidChar(vector<vector<char>>& board, 
                 const vector<vector<int>>& Pos2Blk,
                 int row, int col, char ch) 
{
    for (auto val : board[row]) {
        if (ch == val) return false;
    }
    for (int i=0; i<9; i++) {
        if (ch == board[i][col]) return false;
    }
    
    int blk_id = Pos2Blk[row][col];
    
    int min_row = blk_id / 3 * 3;
    int max_row = min_row + 2;
    int min_col = col / 3 * 3; 
    int max_col = min_col + 2;
    
    for (int i=min_row; i<=max_row; i++) {
        for (int j=min_col; j<=max_col; j++) {
            if (ch == board[i][j]) {
                return false; 
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) 
{
    const vector<vector<int>> Pos2Blk = {
        {0, 0, 0, 1, 1, 1, 2, 2, 2},
        {0, 0, 0, 1, 1, 1, 2, 2, 2},
        {0, 0, 0, 1, 1, 1, 2, 2, 2},
        {3, 3, 3, 4, 4, 4, 5, 5, 5},
        {3, 3, 3, 4, 4, 4, 5, 5, 5},
        {3, 3, 3, 4, 4, 4, 5, 5, 5},
        {6, 6, 6, 7, 7, 7, 8, 8, 8},
        {6, 6, 6, 7, 7, 7, 8, 8, 8},
        {6, 6, 6, 7, 7, 7, 8, 8, 8}
    };
    
    struct Grid {
        int row;
        int col;
        int idx; 
        vector<char> avail_chars; 
        
        Grid(int r=0, int c=0) : row(r), col(c), avail_chars({}) { idx = -1; }
    };

    vector<set<char>> avail_row_sets;
    vector<set<char>> avail_col_sets;
    vector<set<char>> avail_blk_sets;
    
    for (int v=1; v<=9; v++) {
        set<char> tmp = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        avail_row_sets.push_back(tmp);
        avail_col_sets.push_back(tmp);
        avail_blk_sets.push_back(tmp);
    }
    
    for (int r=0; r<9; r++) {
        for (int c=0; c<9; c++) {
            if (board[r][c] != '.') {
                avail_row_sets[r].erase(board[r][c]);
                avail_col_sets[c].erase(board[r][c]);
                avail_blk_sets[Pos2Blk[r][c]].erase(board[r][c]);
            }
        }
    }
    
    vector<Grid *> to_fill;
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (board[i][j] == '.') {
                Grid * p = new Grid(i, j);
                p->avail_chars = get_avail_chars(avail_row_sets, 
                                                 avail_col_sets, 
                                                 avail_blk_sets, 
                                                 Pos2Blk, i, j); 
                to_fill.push_back(p);
            }
        }
    }
    
    int size = to_fill.size();
    for (int i=0; i<size; ) {
        to_fill[i]->idx ++;

        if (to_fill[i]->idx >= to_fill[i]->avail_chars.size()) {
            to_fill[i]->idx = -1;
            board[to_fill[i]->row][to_fill[i]->col] = '.';
            
            if (--i < 0)  break;
            else continue;
        }
        
        char ch = to_fill[i]->avail_chars[to_fill[i]->idx];
        int row = to_fill[i]->row;
        int col = to_fill[i]->col;
        
        bool result = isValidChar(board, Pos2Blk, row, col, ch);
        if ( result ) {
            board[row][col] = ch;
            ++ i;
        }
        else {
            if (to_fill[i]->idx < to_fill[i]->avail_chars.size()) {
                continue;  // i is not changed, just increase idx 
            }
            else {
                to_fill[i]->idx = -1;  // recall i 
                if (--i < 0) break;
            }
        }
    }
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    PrintBoard(board);
    solveSudoku(board);
    PrintBoard(board);
    
    return 0;
}
