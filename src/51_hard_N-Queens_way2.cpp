class Solution {
private:
    vector<vector<string>> result = {};

private:
    vector<string> convert(vector<vector<int>>& vv) {
        const int size = vv.size();
        vector<string> result{};

        for (int i=0; i<size; i++) {
            string tmp(size, '.');
            for (int j=0; j<size; j++) {
                if (vv[i][j]) tmp[j] = 'Q';
            }
            result.push_back(tmp);
        }
        return result;
    }

    bool valid_pos(vector<vector<int>>& vv, int row, int col) {
        const int size = vv.size();

        // check row
        for (int i=0; i<size; i++) {
            if (vv[row][i] != 0) return false;
        }
        
        // check col
        for (int i=0; i<size; i++) {
            if (vv[i][col] != 0) return false;
        }

        // check left slash
        int a = row-1; 
        int b = col-1;
        while (a >=0 && b>=0) {
            if (vv[a--][b--] != 0) return false;
        }

        // check right slash
        a = row - 1;
        b = col + 1;
        while (a>=0 && b<size) {
            if (vv[a--][b++] != 0) return false;
        }

        return true;
    }

    void go(int n, vector<vector<int>>& vv, int row) {
        if (n == row) {
            result.push_back(convert(vv));
            return;
        }

        for (int j=0; j<n; j++) {
            if (valid_pos(vv, row, j)) {
                vv[row][j] = 1;
                go(n, vv, row+1);
                vv[row][j] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> vv{};
        for (int i=0; i<n; i++) {
            vector<int> tmp(n, 0);
            vv.push_back(tmp);
        }

        go(n, vv, 0);
        return result;
    }
};