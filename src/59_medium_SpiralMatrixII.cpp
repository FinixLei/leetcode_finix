/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
*/

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print_vec(vector<T> vec)
{
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

template <typename T>
void print_vecvec(vector<vector<T>> vv) 
{
    for (auto vec : vv) {
        for (auto v : vec) { cout << v << " "; }
        cout << endl;
    }
}

vector<vector<int>> generateMatrix(int n) 
{
    enum DIRECT {
        RIGHT = 0,
        DOWN, 
        LEFT, 
        UP
    };
    
    int total = n * n;
    
    vector<vector<int>> result;
    result.reserve(n);
    vector<int> vec; 
    vec.reserve(n);
    for (int i=0; i<n; ++i) { vec.push_back(0); }
    for (int i=0; i<n; ++i) { result.push_back(vec); }
    
    int top=0, bottom=n, left=-1, right=n;
    int direct = RIGHT; 
    pair<int, int> pos{0, 0};
    
    int count = 0;
    while (count < total) {
        int x=pos.first, y=pos.second;
        result[x][y] = ++count;
        
        switch (direct) {
        case RIGHT:
            y ++;
            if (y >= right) {
                y--;
                x++;
                direct = DOWN;
                right--;
            }
            break;
            
        case DOWN:
            x ++;
            if (x >= bottom) {
                x--;
                y--;
                direct = LEFT;
                bottom--;
            }
            break;
            
        case LEFT:
            y --;
            if (y <= left) {
                y++;
                x--;
                direct = UP;
                left++;
            }
            break;
            
        case UP:
            x --; 
            if (x <= top) {
                x++;
                y++;
                direct = RIGHT; 
                top ++;
            }
            break;
            
        default:
            cout << "Should Never hit here\n";
            break;
        }
        
        pos = make_pair(x, y);
    }
    
    return result;
}


int main()
{
    vector<vector<int>> result;
    result = generateMatrix(3);
    print_vecvec(result);
    
    result = generateMatrix(4);
    print_vecvec(result);
    
    result = generateMatrix(5);
    print_vecvec(result);
    
    return 0;
}
