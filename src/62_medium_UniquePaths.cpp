/*
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    How many possible unique paths are there?

    Input: m = 3, n = 7
    Output: 28

    Input: m = 3, n = 2
    Output: 3
*/

#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
    if (m == 1 || n == 1) return 1;
    
    int **array = new int * [m];
    for (int i=0; i<m; i++) {
        array[i] = new int [n];
    }
    
    for (int i=0; i<n; i++) {
        array[0][i] = 1;
    }
    for (int i=0; i<m; i++) {
        array[i][0] = 1;
    }
    
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++) {
            array[i][j] = array[i-1][j] + array[i][j-1];
        }
    }
    int result = array[m-1][n-1];
    
    for (int i=0; i<m; i++) {
        delete [] array[i];
    }
    delete [] array;
    
    return result;
}

int main()
{
    int m=3, n=7;
    int result = uniquePaths(m, n);
    cout << "m: " << m << ", n: " << n << ", result: " << result << endl;
    
    return 0;
}
