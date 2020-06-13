/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

#include <iostream>
#include <vector>
using namespace std;

void print_vec2d(vector<vector<int>>& vv)
{
    for (auto v : vv) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    
    vector<vector<int>> vec(n);
    for (int i=0; i<n; i++) {
        vec[i].resize(n);
    }
    
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>=0; j--) {
            vec[i][n-1-j] = matrix[j][i];
        }
    }
    
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix[i][j] = vec[i][j];
        }
    }
}

int main()
{
    vector<vector<int>> v1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    print_vec2d(v1);
    rotate(v1);
    print_vec2d(v1);
    
    return 0;
}
