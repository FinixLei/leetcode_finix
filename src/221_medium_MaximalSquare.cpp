// Way-1 Time Limit Exceeds
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int record = 0;
        const int rows = matrix.size();
        const int cols = matrix[0].size();

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (matrix[i][j] == '0') continue;

                const int max_size = min(rows-i, cols-j);
                if (max_size < record) break;

                for (int k=record+1; k<=max_size; k++) {
                    bool good = true;
                    for (int r=i; r<i+k; r++) {
                        for (int c=j; c<j+k; c++) {
                            if (matrix[r][c] == '0') {
                                good = false;
                                break; 
                            }
                        }
                        if (!good) break;
                    }
                    if (good && k > record) { 
                        record = k;
                    }
                }
            }
        }
        return record*record;
    }
};

// Way-2. DP
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int record = 0;
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i=0; i<cols; i++) {
            dp[0][i] = matrix[0][i] == '0' ? 0 : 1;
            if (dp[0][i] == 1 && record == 0) record = 1;
        }
        for (int i=0; i<rows; i++) {
            dp[i][0] = matrix[i][0] == '0' ? 0 : 1;
            if (dp[i][0] == 1 && record == 0) record = 1;
        }
        for (int i=1; i<rows; i++) {
            for (int j=1; j<cols; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                }
                else {  // matrix[i][j] == 1
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    if (dp[i][j] > record) record = dp[i][j];
                }
            }
        }
        return record*record;
    }
};