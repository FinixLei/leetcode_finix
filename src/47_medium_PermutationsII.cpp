/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void print_vec1(vector<int>& vec)
{
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void print_vec2(vector<vector<int>>& vec)
{
    for (auto v : vec) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void perm(vector<pair<int, bool>>& vp, vector<int>& item, vector<vector<int>>& result)
{
    if (item.size() == vp.size()) {
        result.push_back(item);
        return;
    }

    for (int i=0; i<vp.size(); i++) {
        if (vp[i].second == false){  // not used yet
            vp[i].second = true;   // use it 
            item.push_back(vp[i].first);
            
            perm(vp, item, result);
            
            item.pop_back();
            vp[i].second = false;  // recover to not-used 
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> item;
    vector<pair<int, bool>> vp;
    
    sort(nums.begin(), nums.end());
    
    for (auto i : nums) {
        vp.push_back(make_pair(i, false));
    }
    
    perm(vp, item, result);
    
    // Remove redundancy
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    return result;
}

int main()
{
    vector<vector<int>> result;
    
    vector<int> nums{1, 1, 2};
    result = permuteUnique(nums);
    print_vec2(result);
    
    vector<int> nums2{-1,2,-1,2,1,-1,2,1};
    result = permuteUnique(nums2);
    print_vec2(result);
    
    return 0;
}
