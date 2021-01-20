/*
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time. 
    The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    Now consider if some obstacles are added to the grids. How many unique paths would there be?
    An obstacle and space is marked as 1 and 0 respectively in the grid.
    
    Example-1
    Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    Output: 2
    
    Example-2
    Input: obstacleGrid = [[0,1],[0,0]]
    Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void PrintVecVec(const T& array) 
{
    for (auto vec : array) {
        for (auto v : vec) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "\n";
}


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    if (obstacleGrid[0][0] == 1) return 0;
    
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    if (obstacleGrid[m-1][n-1] == 1) return 0;
    if (m==1 && n==1) return 1;
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = -1;
            }
        }
    }
    // PrintVecVec(obstacleGrid);
    
    for (int j=1; j<n; j++) {
        if (obstacleGrid[0][j] == -1) {
            for (int k=j; k<n; k++) {
                obstacleGrid[0][k] = -1;
            }
            break;
        }
        else {
            obstacleGrid[0][j] = 1;
        }
    }
    // PrintVecVec(obstacleGrid);
    
    for (int i=1; i<m; i++) {
        if(obstacleGrid[i][0] == -1) {
            for (int k=i; k<m; k++) {
                obstacleGrid[k][0] = -1;
            }
            break;
        }
        else {
            obstacleGrid[i][0] = 1;
        }
    }
    // PrintVecVec(obstacleGrid);
    
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++) {
            if (obstacleGrid[i][j] == -1) continue;
            
            int up = obstacleGrid[i-1][j] < 0 ? 0 : obstacleGrid[i-1][j];
            int left = obstacleGrid[i][j-1] < 0 ? 0 : obstacleGrid[i][j-1];
            obstacleGrid[i][j] = up + left;
        }
    }
    // PrintVecVec(obstacleGrid);
    
    return obstacleGrid[m-1][n-1];
}

int main()
{
    vector<vector<int>> obsGrid = { {0,0,0}, {0,1,0}, {0,0,0} };
    int result = uniquePathsWithObstacles(obsGrid);
    cout << "result = " << result << endl << endl;
    
    obsGrid = { {0, 1}, {0, 0} };
    result = uniquePathsWithObstacles(obsGrid);
    cout << "result = " << result << endl  << endl;
    
    obsGrid = { {0, 0}, {0, 1} };
    result = uniquePathsWithObstacles(obsGrid);
    cout << "result = " << result << endl  << endl;
    
    obsGrid = { {0, 0}, {1, 0} };
    result = uniquePathsWithObstacles(obsGrid);
    cout << "result = " << result << endl  << endl;
    
    return 0;
}