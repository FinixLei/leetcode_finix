/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    set<int> num_set; 
    int max = 0;
    for (auto i : nums) {
        if (i>0) {
            num_set.insert(i);
            if (i > max) max = i;
        }
    }
    if (num_set.size() == 0) return 1;
    
    for (int i=1; i<=max; i++) {
        if (num_set.find(i) == num_set.end()) return i; 
    }
    return max+1;
}

int way2_firstMissingPositive(vector<int>& nums) { 
    vector<int> array;
    int max = 0;
    for (auto i : nums) {
        if (i>0) {
            array.push_back(i);
            if (i > max) max = i;
        }
    }
    sort(array.begin(), array.end());
    if (array.size() == 0 || array[0] > 1) return 1;
    
    for (int i=0; i<=int(array.size())-2; i++) {
        if (array[i] + 1 < array[i+1]) return array[i]+1;
    }
    return max+1;        
}


int main()
{
    // int array[] = {3,4,-1,1};
    int array[] = {7,8,9,11};
    
    vector<int> init(array, array+sizeof(array)/sizeof(int));
    cout << firstMissingPositive(init);
    cout << way2_firstMissingPositive(init);
    
    return 0;
}