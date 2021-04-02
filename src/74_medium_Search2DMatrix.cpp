/*
    Write an efficient algorithm that searches for a value in an m x n matrix. 
    This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


template<typename T> 
void print_vec(vector<T> vec) 
{
    for (auto v : vec) {
        cout << v << " " ; 
    }
    cout << endl;
}


bool searchMatrix_way1(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    if (row == 0) return false; 
    
    int col = matrix[0].size();
    
    int min_num = matrix[0][0];
    int max_num = matrix[row-1][col-1];
    
    if (target < min_num || target > max_num) return false;
    if (target == min_num || target == max_num) return true; 
    
    vector<int> headers;
    headers.reserve(row);
    for (int i=0; i<row; i++) {
        headers.push_back(matrix[i][0]);
    }
    
    auto it = std::lower_bound(headers.begin(), headers.end(), target);
    if ( it != headers.end() ) {
        if (*it == target) return true;
        
        int val = *(--it);
        int i = 0;
        for (; i<row; i++) {
            if (headers[i] == val) break;
        }
        return binary_search(matrix[i].begin(), matrix[i].end(), target);
    }
    else {
        return binary_search(matrix[row-1].begin(), matrix[row-1].end(), target);
    }
    
}


bool searchMatrix_way2(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    if (row == 0) return false; 
    
    int col = matrix[0].size();
    
    int min_num = matrix[0][0];
    int max_num = matrix[row-1][col-1];
    
    if (target < min_num || target > max_num) return false;
    
    int total_num = row * col; 
    
    vector<int> vec;
    vec.reserve(total_num);
    for (int i=0; i<row; ++i) {
        copy(matrix[i].begin(), matrix[i].end(), back_inserter(vec));
    }
    
    return binary_search(vec.begin(), vec.end(), target);
}


int main()
{
    vector<vector<int>> matrix {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    
    int target = 3;
    
    bool result = searchMatrix_way1(matrix, target);
    cout << "result is " << std::boolalpha << result << endl;
    
    matrix = { {1,3} };
    target = 2; 
    cout << "result is " << std::boolalpha << result << endl;
    
    return 0;
}
