/*
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: The triangle looks like:
       2
      3 4
     6 5 7
    4 1 8 3

The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
    Input: 
       -1
      2  3
     1 -1 3
     
     Output: -1
*/

class Solution {
public:
int minPointValue(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& memo) {
    if (memo[i][j] != INT_MIN) return memo[i][j];
    
    int currentPointValue = triangle[i][j];
    if (i == triangle.size()-1) return currentPointValue; 
    
    int r1 = currentPointValue + minPointValue(triangle, i+1, j, memo);
    int r2 = currentPointValue + minPointValue(triangle, i+1, j+1, memo);
    memo[i][j] = min(r1, r2);
    return memo[i][j];
}

int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty()) return 0;
    
    for (int i=0; i<triangle.size(); i++) {
        vector<int> vec;
        vec.reserve(triangle[i].size());
        for (int j=0; j<triangle[i].size(); j++) {
            vec.push_back(INT_MIN);
        }
        memo.push_back(vec);
    }
    
    return minPointValue(triangle, 0, 0, memo);
}
    
private:
    vector<vector<int>> memo;
};
