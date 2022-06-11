/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

#include <iostream>
#include <vector>
using namespace std;

void printVec2D(vector<vector<int>> & vec2D) {
    for (auto vec1D : vec2D) {
        for (auto i : vec1D) cout << i << " ";
        cout << endl;
    }
    cout << endl;
}

void generateVec(vector<int>& inVec, vector<int>& outVec)
{
    if (inVec.size() == 1) {
        outVec = {inVec[0], inVec[0]};
        return; 
    }
    
    outVec = {};
    outVec.push_back(inVec[0]);
    
    for (int i=0; i<inVec.size()-1; i++) {
       outVec.push_back(inVec[i] + inVec[i+1]);
    }
    outVec.push_back(inVec[inVec.size()-1]);
}

vector<vector<int>> generate(int numRows) 
{
    vector<vector<int>> result;
    
    if (numRows <= 0) return result; 

    vector<int> base{1};

    result.push_back(base); 
    vector<int> inVec = base;
    vector<int> outVec; 
    
    for (int i=2; i<=numRows; i++) {
        generateVec(inVec, outVec);
        result.push_back(outVec);
        inVec = outVec; 
    }
    
    return result; 
}

int main()
{
    vector<vector<int>> result = generate(5);
    printVec2D(result);
    
    return 0;
}