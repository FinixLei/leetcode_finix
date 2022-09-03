/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Example 1:
    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
    
Example 2:
    Input: s = "a"
    Output: [["a"]]
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


template<typename T>
void printVector(vector<T>& vec) {
    for (auto& v : vec) cout << v << " ";
    cout << endl;
}

template<typename T>
void printVector2D(vector<vector<T>>& vec2D) {
    for (auto& vec : vec2D) printVector(vec);
}


bool isPString(const string& line, int start, int end)
{
    if (start < 0 || end > line.size() || start > end) return false;
    
    for (int i=start, j =end-1; i<j; i++, j--) {
        if (line[i] != line[j]) return false;
    }
    return true;
}

bool helper(const string& line, int start, int blockSize, vector<string>& oneResult, vector<vector<string>>& finalResult)
{
    if (start >= line.size()) return false;
    
    bool goodSubString = isPString(line, start, start+blockSize);
    
    if (!goodSubString) return false; 
    
    string tmp;
    for (int i=start; i<start+blockSize; i++) {
        tmp.push_back(line[i]);
    }
    oneResult.push_back(tmp);
    
    if (line.size() == start + blockSize) {
        finalResult.push_back(oneResult); 
        oneResult.pop_back();
        return true;
    }
    
    int newStart = start + blockSize; 
    bool thisResult = false;
    
    for (int newBlockSize=1; newBlockSize <= line.size() - newStart; newBlockSize++) {
        bool tmpResult = helper(line, newStart, newBlockSize, oneResult, finalResult); 
        if (tmpResult) thisResult = true; 
    }
    
    oneResult.pop_back();
    
    return thisResult; 
}


vector<vector<string>> partition(string s) 
{
    vector<vector<string>> finalResult;

    int strSize = s.size();
    
    for (int blockSize=1; blockSize<=strSize; blockSize++) {
        vector<string> oneResult; 
        helper(s, 0, blockSize, oneResult, finalResult);
    }
    
    return finalResult;
}

int main()
{
    string line = "aabccbafg";
    vector<vector<string>> result; 
    
    bool checkResult = isPString(line, 1, 7);
    cout << std::boolalpha << checkResult << endl; 
    
    line = "aab";
    result = partition(line); 
    printVector2D(result);
    
    line = "aabccbafg";
    result = partition(line); 
    printVector2D(result);
    
    return 0;
}
