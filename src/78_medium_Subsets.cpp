/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


void print_vec2D(vector<vector<int>>& vec2D)
{
    for(auto vec : vec2D) {
        for (auto v : vec) cout << v << " ";
        cout << endl;
    }
    cout << endl;
}

void get_n_elements(list<int>& numbers, int n, vector<int>& one_result, vector<vector<int>>& result)
{
    if (numbers.size() < n) return;
    
    if (0 == n) {
        result.push_back(one_result);
        return;
    }
    
    list<int> tmp = numbers;
    
    while(tmp.size() > 0) {
        one_result.push_back(tmp.front());
        
        tmp.pop_front();
        get_n_elements(tmp, n-1, one_result, result);
        
        one_result.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    int len = nums.size();
    if (len == 0) return {{}};
    if (len == 1) return { {}, {nums[0]} };
    
    vector<vector<int>> result{{}};
    
    for (int n=1; n<len; ++n) {
        vector<int> one_result{};
        list<int> tmp(nums.begin(), nums.end());
        get_n_elements(tmp, n, one_result, result);
    }
    
    result.push_back(nums);
    return result;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    
    vector<vector<int>> result {};
    vector<int> one_result {};
    
    result = subsets(nums);
    print_vec2D(result);
    
    return 0;
}
