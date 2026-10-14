void markRecords(char** grid, int** visited, int rows, int cols, int i, int j, int currRecord) {
    assert(currRecord > 0);
    if (grid[i][j] != '1') return;
    if (visited[i][j] != 0) return;

    visited[i][j] = currRecord;

    if (i-1 >= 0 && grid[i-1][j]=='1' && visited[i-1][j]==0) {
        markRecords(grid, visited, rows, cols, i-1, j, currRecord);
    }
    if (i+1 < rows && grid[i+1][j]=='1' && visited[i+1][j]==0) {
        markRecords(grid, visited, rows, cols, i+1, j, currRecord);
    }
    if (j-1 >= 0 && grid[i][j-1]=='1' && visited[i][j-1]==0) {
        markRecords(grid, visited, rows, cols, i, j-1, currRecord);
    }
    if (j+1 < cols && grid[i][j+1]=='1' && visited[i][j+1]==0) {
        markRecords(grid, visited, rows, cols, i, j+1, currRecord);
    }
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;
    int one_count = 0, tmp_count = 0;
    int i=0, j=0;
    int currRecord = 1;

    int ** visited = (int **) malloc (sizeof(int*) * rows);
    for (i=0; i<rows; i++) {
        visited[i] = (int *) malloc (sizeof(int) * cols);
    }

    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            visited[i][j] = 0;
            if (grid[i][j] == '1') one_count++;
        }
    }

    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            if (grid[i][j] == '1' && visited[i][j] == 0) {
                markRecords(grid, visited, rows, cols, i, j, currRecord);
                currRecord ++;
            }
        }
    }
    currRecord -= 1;

    for (i=0; i<rows; i++) free(visited[i]);
    free(visited);
    return currRecord;
}
