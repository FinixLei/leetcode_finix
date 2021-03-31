/*
    Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

    Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?
    
    Example: 
        Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
        Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/


#include <iostream>
#include <vector>
#include <set> 
using namespace std;

void print_2Dvec(vector<vector<int>> & matrix)
{
    for (auto vec : matrix) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void setZeroes(vector<vector<int>>& matrix) 
{
    int rows = matrix.size();
    if (rows == 0) return; 
    int cols = matrix[0].size();
    
    set<int> zero_rows;
    set<int> zero_cols;
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (matrix[i][j] == 0) {
                zero_rows.insert(i);
                zero_cols.insert(j);
            }
        }
    }
    
    for (int i=0; i<rows; i++) {
        if (zero_rows.find(i) != zero_rows.end()) {
            for (int j=0; j<cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    for (int j=0; j<cols; j++) {
        if (zero_cols.find(j) != zero_cols.end()) {
            for (int i=0; i<rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}


int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1}, 
        {1, 0, 1}, 
        {1, 1, 1}
    }; 
    
    print_2Dvec(matrix);
    setZeroes(matrix);
    print_2Dvec(matrix);
    
    matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    print_2Dvec(matrix);
    setZeroes(matrix);
    print_2Dvec(matrix);
 
    return 0;
}