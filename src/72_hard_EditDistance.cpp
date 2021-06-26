/*
    Given two strings word1 and word2, 
    return the minimum number of operations required to convert word1 to word2.

    You have the following three operations permitted on a word:
    - Insert a character
    - Delete a character
    - Replace a character

    Example 1:
        Input: word1 = "horse", word2 = "ros"
        Output: 3
        Explanation: 
        horse -> rorse (replace 'h' with 'r')
        rorse -> rose (remove 'r')
        rose -> ros (remove 'e')
*/


#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int minDistance(string& word1, string& word2) 
{
    const int len1 = word1.size() + 1;
    const int len2 = word2.size() + 1;
    
    if (len1 == 1) return len2-1; 
    if (len2 == 1) return len1-1;
    
    int dp[len1][len2];

    for (int i=0; i<len2; ++i) {
        dp[0][i] = i;
    }
    
    for (int i=0; i<len1; ++i) {
        dp[i][0] = i;
    }
    
    for (int i=1; i<len1; ++i) {
        for (int j=1; j<len2; ++j) {
            if (word1[i-1] != word2[j-1]) {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
            else {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    for (int i=0; i<len1; i++) {
        for (int j=0; j<len2; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return dp[len1-1][len2-1];
}


int main()
{
    string s1 = "", s2 = "";
    int minDist = -1;
    
    s1 = "horse";
    s2 = "ros";
    minDist = minDistance(s1, s2);
    cout << s1 << endl << s2 << endl << minDist << endl;
    
    s1 = "inten";
    s2 = "execu";
    minDist = minDistance(s1, s2);
    cout << s1 << endl << s2 << endl << minDist << endl;
    
    s1 = "a";
    s2 = "a";
    minDist = minDistance(s1, s2);
    cout << s1 << endl << s2 << endl << minDist << endl;
    
    s1 = "gorithm";
    s2 = "truistic";
    minDist = minDistance(s1, s2);
    cout << s1 << endl << s2 << endl << minDist << endl;
    
    return 0;
}
