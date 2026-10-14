class Solution {
public:
    // return mark or not
    bool mark(vector<vector<int>>& visited, vector<vector<char>>& grid, int i, int j, const int rows, const int cols) {
        if (visited[i][j] == 1 || grid[i][j] == '0') return false;
        visited[i][j] = 1;

        if (i-1 >= 0) mark(visited, grid, i-1, j, rows, cols);
        if (i+1 < rows) mark(visited, grid, i+1, j, rows, cols);
        if (j-1 >= 0) mark(visited, grid, i, j-1, rows, cols);
        if (j+1 < cols) mark(visited, grid, i, j+1, rows, cols);
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();

        vector<vector<int>> visited;

        for (int i=0; i<rows; i++) {
            vector<int> vec(cols, 0);
            visited.push_back(vec);
        }

        int count = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] != '0') {
                    if (mark(visited, grid, i, j, rows, cols)) count ++;
                }
            }
        }
        return count;
    }
};
