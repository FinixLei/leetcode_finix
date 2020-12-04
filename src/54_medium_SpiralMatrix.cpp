/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
    1 2 3
    4 5 6
    7 8 9

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
    1  2  3  4
    5  6  7  8
    9 10 11 12

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <vector>
#include <iostream>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    enum Direct {
        MoveRight = 0,
        MoveDown,
        MoveLeft,
        MoveUp
    };

    int row = matrix.size();
    int col = matrix[0].size();
    
    vector<int> result;
    
    int count = 0;
    int TOP=1, LEFT=0, RIGHT=col-1, BOTTOM=row-1;
    int x=0, y=0;
    enum Direct direct = MoveRight;

    while (true) 
    {
        result.push_back(matrix[x][y]);
        if (++count >= row*col) break;
        
        switch (direct) {
        case MoveRight:
            if (y >= RIGHT) {
                x ++;
                RIGHT --;
                direct = MoveDown;
            }
            else {
                y ++;
            }
            break;
            
        case MoveDown:
            if (x >= BOTTOM) {
                y --;
                BOTTOM --;
                direct = MoveLeft;
            }
            else {
                x ++;
            }
            break;
            
        case MoveLeft:
            if (y <= LEFT) {
                x --;
                LEFT ++;
                direct = MoveUp;
            }
            else {
                y --;
            }
            break;
            
        case MoveUp:
            if (x <= TOP) {
                y ++;
                TOP ++;
                direct = MoveRight;
            }
            else {
                x --;
            }
            break;
            
        default: 
            cout << "Never get here\n";
        }
    }

    return result; 
}

int main()
{
    {
        vector<vector<int>> matrix{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8 ,9}
        };
        
        vector<int> result = spiralOrder(matrix);
        for (auto v : result) cout << v << " ";
        cout << endl;
    }
    
    {
        vector<vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };
        
        vector<int> result = spiralOrder(matrix);
        for (auto v : result) cout << v << " ";
        cout << endl;
    }

    return 0;
}