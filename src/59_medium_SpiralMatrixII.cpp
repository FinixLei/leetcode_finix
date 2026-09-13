/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v2d(n, vector<int>(n, 0));

        int direction = 0; // 0: ->, 1: down, 2: <-, 3: up
        const int total = n * n;
        int curr_num = 1;
        int i=0, j=0;

        while (curr_num <= total) {
            v2d[i][j] = curr_num ++;

            if (direction == 0) {
                j ++;
                if (j >= n || v2d[i][j] > 0) {
                    j --;
                    i ++;
                    direction = 1;
                }
            }
            else if (direction == 1) {
                i ++;
                if (i >= n || v2d[i][j] > 0) {
                    i --;
                    j --;
                    direction = 2;
                }
            }
            else if (direction == 2) {
                j --;
                if (j < 0 || v2d[i][j] > 0) {
                    j ++;
                    i --;
                    direction = 3;
                }
            }
            else {  // direction == 3
                i --;
                if (v2d[i][j] > 0) {  // no need to check if i < 0
                    i ++;
                    j ++;
                    direction = 0;
                }
            }
        }

        return v2d;
    }
};
