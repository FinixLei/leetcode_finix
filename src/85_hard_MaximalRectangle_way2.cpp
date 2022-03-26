#include <vector>
#include <iostream>
using namespace std; 


int getOneItemRec(vector<vector<char>>& matrix, int maxRowNum, int maxColNum, int i, int j) 
{
    if(i > maxRowNum || j > maxColNum) return 0;
    if (matrix[i][j] == '0') return 0;
    
    int startRow = i;
    int endRow = i;
    for (int row=startRow+1; row<=maxRowNum; row++) {
        if (matrix[row][j] == '1') endRow = row;
        else break;
    }
    
    int result = 1;
    int minCols = 9999;
    
    for (int row=startRow; row <= endRow; row++) {
        int onesInCurrRow = 0;
        for (int k=j; k<=maxColNum; k++) {
            if (matrix[row][k] == '1') onesInCurrRow ++;
            else break;
        }
        
        minCols = min(minCols, onesInCurrRow);
        
        int tmpRec = minCols * (row-startRow+1);
        result = max(max(tmpRec, onesInCurrRow), result); 
    }
    
    return result;
}

int maximalRectangle(vector<vector<char>>& matrix) 
{
    if (matrix.size() == 0) return 0;
    
    int maxRowNum = matrix.size() - 1;
    int maxColNum = matrix[0].size() - 1;
    
    int result = 0;
    
    for(int i=0; i<=maxRowNum; i++) {
        for (int j=0; j<=maxColNum; j++) {
            if (matrix[i][j] == '1') {
                int tmpResult = getOneItemRec(matrix, maxRowNum, maxColNum, i, j);
                if (tmpResult > result) {
                    // cout << "change result to " << tmpResult << ": i=" << i << ", j=" << j << endl;
                    result = tmpResult; 
                }
            }
        }
    }
    
    return result;
}

int main()
{
    vector<vector<char>> matrix {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'}, 
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    int result = maximalRectangle(matrix);
    cout << "result = " << result << endl;
    
    matrix = {
        {'1', '0', '1', '1', '1'},
        {'0', '1', '0', '1', '0'},
        {'1', '1', '0', '1', '1'},
        {'1', '1', '0', '1', '1'},
        {'0', '1', '1', '1', '1'}
    };
    
    result = maximalRectangle(matrix);
    cout << "result = " << result << endl;
    
    return 0;
}
