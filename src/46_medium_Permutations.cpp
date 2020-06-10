/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <iostream>
#include <vector>
#include <set>
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
        if (vp[i].second == false) { // not used 
            vp[i].second = true;     // use it 
            item.push_back(vp[i].first);
            
            perm(vp, item, result);
            
            item.pop_back();
            vp[i].second = false;    // recover to not-used 
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> item;
    vector<pair<int, bool>> vp;
    
    for (auto i : nums) {
        vp.push_back(make_pair(i, false));
    }
    
    perm(vp, item, result);
    
    return result;
}

int main()
{
    vector<int> nums{1, 2, 3};
    
    vector<vector<int>> result = permute(nums);
    print_vec2(result);
    
    return 0;
}
