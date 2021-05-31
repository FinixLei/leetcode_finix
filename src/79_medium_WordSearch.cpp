/*
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, 
    where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
    
    Example-1. 
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;


/****************************************************/
/*  Way-1. Recusive Way                             */
/****************************************************/
bool _exist(vector<vector<char>>& board, bool * hits, string& word, const int rows, const int cols, int si, int sj, int wi)
{
    if ( si < 0 || sj < 0 || si >= rows || sj >= cols ) return false;
    if ( hits[si*cols+sj] ) return false;
    
    if (board[si][sj] == word[wi]) {
        // cout << "Hit: " << si << ", " << sj << ", " << wi << ", " << board[si][sj] << endl;
        if (wi == word.size() - 1) return true; 
        
        hits[si*cols+sj] = true;
        if ( _exist(board, hits, word, rows, cols, si-1, sj, wi+1) ) return true;
        if ( _exist(board, hits, word, rows, cols, si, sj+1, wi+1) ) return true;
        if ( _exist(board, hits, word, rows, cols, si+1, sj, wi+1) ) return true;
        if ( _exist(board, hits, word, rows, cols, si, sj-1, wi+1) ) return true;
        
        hits[si*cols+sj] = false; 
        // cout << "Cancel: " << si << ", " << sj << ", " << wi << ", " << board[si][sj] << endl;
        return false;
    }
    else {
        hits[si*cols+sj] = false;
        return false;
    }
}

/****************************************************/
/*  Way-1. Recusive Way                             */
/****************************************************/
bool exist(vector<vector<char>>& board, string& word) 
{
    int rows = board.size();
    if (rows == 0) return false;
    
    int len_word = word.size();
    if (len_word == 0) return true;
    
    int cols = board[0].size();
    if (rows * cols < word.size()) return false;
    
    bool * hits = new bool [rows*cols]; 
    bool result = false; 
    
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            for (int k=0; k<rows*cols; k++) {  // clear hits every time
                hits[k] = false;
            }
            if ( _exist(board, hits, word, rows, cols, i, j, 0) ) {
                result = true;
                break;
            }
        }
    }
    
    return result;
}

/****************************************************/
/*  Way-2. Non-Recusive but Stack way               */
/****************************************************/
bool _exist2(vector<vector<char>>& board, string& word, const int rows, const int cols, int si, int sj)
{
    if (si >= rows || sj >= cols || si <0 || sj < 0) return false;
    
    bool result = false;
    
    bool hits[rows][cols];
    for(int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            hits[i][j] = false;
        }
    }
    
    int len_word = word.size();
    int word_index = 0;
    stack<tuple<int, int, int>> candidates; 
    
    candidates.push(make_tuple(si, sj, word_index));
    
    // Firstly, Push to the stack;
    // If matches word, do not pop; otherwise, pop; 
    // When push to stack, set hits flag as true;
    // When pop, set hits flag as false; 
    while (!candidates.empty()) 
    {
        tuple<int, int, int> t = candidates.top();
        int i  = std::get<0>(t);
        int j  = std::get<1>(t);
        int wi = std::get<2>(t);
        
        if (hits[i][j] == false) {
            if (board[i][j] == word[wi]) {
                if (wi == len_word-1) {
                    return true;
                }
                else {
                    hits[i][j] = true; 
                    bool no_push = true;
                    if (i-1 >=0    && !hits[i-1][j]) { no_push = false; candidates.push(make_tuple(i-1, j, wi+1)); }
                    if (j+1 < cols && !hits[i][j+1]) { no_push = false; candidates.push(make_tuple(i, j+1, wi+1)); }
                    if (i+1 < rows && !hits[i+1][j]) { no_push = false; candidates.push(make_tuple(i+1, j, wi+1)); }
                    if (j-1 >=0    && !hits[i][j-1]) { no_push = false; candidates.push(make_tuple(i, j-1, wi+1)); }

                    if (no_push) {    // Failed
                        candidates.pop();
                        hits[i][j] = false;
                    }
                }
            }
            else {
                // not match, do nothing except pop 
                hits[i][j] = false;
                candidates.pop();
            }
        }
        else {  
        // hits[i][j] being true means this item should be poped now, 
        // as it was once pushed but all its next candidates failed, so pop it now. 
            hits[i][j] = false;
            candidates.pop();
        }
    }
    
    return result;
}

/****************************************************/
/*  Way-2. Non-Recusive but Stack way               */
/****************************************************/
bool exist2(vector<vector<char>>& board, string& word) 
{
    int rows = board.size();
    if (rows == 0) return false;
    
    int len_word = word.size();
    if (len_word == 0) return true;
    
    int cols = board[0].size();
    
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            if ( _exist2(board, word, rows, cols, i, j) ) return true;
        }
    }
    
    return false;
}


int main()
{
    {
        vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        string word = "ABCCED";
        bool result = exist(board, word);
        cout << std::boolalpha << result << endl;
        result = exist2(board, word);
        cout << std::boolalpha << result << endl;
        cout << "------------------------------------\n";
        
        word = "ABCB";
        result = exist(board, word);
        cout << std::boolalpha << result << endl;  // false 
        result = exist2(board, word);
        cout << std::boolalpha << result << endl;  // false
        cout << "------------------------------------\n";
    }
    
    {
        vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'E', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        
        string word = "ABCESEEEFS"; 
        bool result = exist(board, word);
        cout << std::boolalpha << result << endl;
        result = exist2(board, word);
        cout << std::boolalpha << result << endl;
        cout << "------------------------------------\n";
        
        word = "SEE";
        result = exist(board, word);
        cout << std::boolalpha << result << endl;
        result = exist2(board, word);
        cout << std::boolalpha << result << endl;
        cout << "------------------------------------\n";
        
    }
    
    {
        vector<vector<char>> board = {
            {'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a'}, 
            {'a', 'a', 'a', 'a'}
        };
        string word = "aaaaaaaaaaaaa";
        bool result = exist(board, word);
        cout << std::boolalpha << result << endl;  // false 
        result = exist2(board, word);
        cout << std::boolalpha << result << endl;
        cout << "------------------------------------\n";
    }
    
    return 0;
}
