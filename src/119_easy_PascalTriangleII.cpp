/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
    Input: rowIndex = 3
    Output: [1,3,3,1]
*/

#include <iostream>
#include <vector>
using namespace std;

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

vector<int> getRow(int rowIndex)
{
    if (rowIndex < 0) return {}; 
    if (rowIndex == 0) return {1};
    
    vector<int> base{1};
    vector<int> inVec = base;
    vector<int> outVec; 
    
    for (int i=1; i<=rowIndex; i++) {
        generateVec(inVec, outVec);
        inVec = outVec; 
    }
    
    return outVec; 
}
