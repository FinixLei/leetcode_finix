// This version is TLE(Time Limit Exceed) although it's correct.

class Solution {
private: 
    bool search_word(const vector<vector<char>>& board, const int rows, const int cols, 
                     int i, int j, const string& word, int pos, 
                     vector<vector<bool>>& visited) {
        if (pos == word.size()) return true;
        if (0 <= i && i < rows && 0 <= j && j < cols && visited[i][j]==false && board[i][j] == word[pos]) {
            visited[i][j] = true;
            bool res = false;
            // up
            res = search_word(board, rows, cols, i-1, j, word, pos+1, visited);
            if (res) return true;

            // down
            res = search_word(board, rows, cols, i+1, j, word, pos+1, visited);
            if (res) return true;

            // left
            res = search_word(board, rows, cols, i, j-1, word, pos+1, visited);
            if (res) return true;

            // right
            res = search_word(board, rows, cols, i, j+1, word, pos+1, visited);
            if (res) return true;

            visited[i][j] = false;
            return false;
        }
        return false;
    }

    bool find_one_word(vector<vector<char>>& board, const string& word) {
        if (word.size() == 0) return false;
        const int rows = board.size();
        if (rows == 0) return false;
        const int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (board[i][j] == word[0]) {
                    if (search_word(board, rows, cols, i, j, word, 0, visited)) return true;
                }
            }
        }
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> vec;
        for (auto& w : words) {
            if (find_one_word(board, w)) {
                vec.push_back(w);
            }
        }
        return vec;
    }
};
