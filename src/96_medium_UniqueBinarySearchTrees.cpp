/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
    Input: n = 3
    Output: 5
*/

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


int _getTreeCount(int beg, int end, unordered_map<int, int>& trees2count) {
    if(beg >= end) return 1;
    
    int treeTotalNumber = end - beg + 1; 
    
    if (trees2count.find(treeTotalNumber) != trees2count.end()) {
        return trees2count[treeTotalNumber];
    }
    
    int sum = 0;
    
    for(int i=beg; i<=end; i++) {
        int leftTreesCount  = _getTreeCount(beg, i-1, trees2count);
        int rightTreesCount = _getTreeCount(i+1, end, trees2count);
        sum += leftTreesCount * rightTreesCount;
    }
    
    trees2count[treeTotalNumber] = sum;
    return sum;
}

int numTrees(int n) {
    unordered_map<int, int> trees2count;
    trees2count[1] = 1;
    trees2count[2] = 2;
    return _getTreeCount(1, n, trees2count);
}

// Way-2. DP

int numTreesWay2(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        int left = 0;
        int right = i - 1;

        while(left < i && right >= 0)
        {
            dp[i] += dp[left] * dp[right];
            left ++;
            right --;
        }
    }
    
    return dp[n];
}


int main()
{
    int n = 3;
    int result = numTrees(n);
    cout << "There are " << result << " trees for number " << n << endl;
    
    n = 5;
    result = numTrees(n);
    cout << "There are " << result << " trees for number " << n << endl;
    
    n = 18;
    result = numTrees(n);
    cout << "There are " << result << " trees for number " << n << endl;
    
    n = 18;
    result = numTreesWay2(n);
    cout << "There are " << result << " trees for number " << n << endl;
    
    return 0;
}
