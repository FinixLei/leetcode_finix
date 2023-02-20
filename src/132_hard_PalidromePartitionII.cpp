/*
    Given a string s, partition s such that every substring of the partition is a palindrome
    Return the minimum cuts needed for a palindrome partitioning of s.

    Example 1:
        Input: s = "aab"
        Output: 1
        Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
        
    Example 2:
        Input: s = "a"
        Output: 0
        
    Example 3:
        Input: s = "ab"
        Output: 1
*/

class Solution {
private:
    // isPaliArray[i][j] means, if s[i,j] is true, then it is a palindrome string
    vector<vector<bool>> isPaliArray;

public:
    int minCut(string s) {
        int size = s.size();
        isPaliArray = {};
        
        // Step 1. construct isPaliArray
        // 1.1> make all isPaliArray[i][i] = true, and make all other items to be false 
        // this step makes all the single char as palindrome string 
        for (int i=0; i<size; i++) {
            vector<bool> oneDimArray;
            for (int j=0; j<size; j++) {
                oneDimArray.push_back(i!=j ? false : true);
            }
            isPaliArray.push_back(oneDimArray);
        }
        
        // 1.2> generate the results for all isPaliArray[i][i+1] 
        // this only needs to check if s[i] == s[i+1]
        // this step generates the results for all the 2-char strings 
        for (int i=0; i<size-1; i++) {
            if (s[i] == s[i+1]) isPaliArray[i][i+1] = true; 
        }
        
        // 1.3> this step generates the results for all the 3-char, 4-char, ..., n-char strings. 
        // once we have all the results of 1-char strings, then we can deduce the results of 3-char strings;
        // once we have all the results of 2-char strings, then we can deduce all the results of 4-char strings;
        // and so on; 
        // the results of 1-char strings and 2-char strings have been resolved at step 1.1 and 1.2. 
        // this part of programming is subtle 
        // i is the start of the string; 
        // k is the length of the string, so i+k-1 is the end of the string; 
        // the longest string we want to check is the original string itself, so the scope of k is [3, size] 
        // since already know the result of length as (k-2)-char strings, 
        // only need to check whether the first char and the end char are the same for current k-char string, i.e. 
        // if (s[i] == s[j] && isPaliArray[i+1][j-1]) { isPaliArray[i][j] = true; }
        // Here, isPaliArray[i+1][j-1] just means whether that (k-2)-char string is palindrome. 
        for (int k=3; k<=size; k++) {
            for (int i=0; i<size-k+1; i++) {
                int j = i+k-1;
                if (s[i] == s[j] && isPaliArray[i+1][j-1]) {
                    isPaliArray[i][j] = true;
                }
            }
        }
        
        // Step 2. Use DP to calculate cuts array 
        // cuts[i] means s[0,i] needs how many cuts at least 
        // Before calculating cuts[i], need to get the results from cuts[0] to cuts[i-1]
        // The worst result is, cuts[i]=i, so intializedly, assign i to cuts[i]; 
        // Then, for 0..j, (j belongs to [1, i-1]), if s[j+1, i] is palindrome, 
        // then cuts[i] could be just cuts[j]+1. Here, 1 means s[j+1,i]. 
        // So, cuts[i] = min(custs[i], cuts[j]+1), if isPaliArray[j+1][i] is true. 

        vector<int> cuts;
        for (int i=0; i<size; i++) cuts.push_back(i);
        
        for (int i=1; i<size; i++) {
            if (isPaliArray[0][i]) {
                cuts[i] = 0;
            }
            else {
                for (int j=0; j<i; j++) {
                    if (isPaliArray[j+1][i]) {
                        cuts[i] = min(cuts[i], cuts[j]+1);
                    }
                }
            }
        }

        return cuts[size-1];
    }
};