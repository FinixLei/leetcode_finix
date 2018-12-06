/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

#include <iostream>
#include <vector>
using namespace std;

void get_solution(vector<vector<int> >& result, vector<int>& item, int pos, 
                  const vector<int>& candidates, int target)
{
    if (target == 0) {
        vector<int> result_item(item);
        result.push_back(result_item);
    }
    else if(target > 0) {
        int size = candidates.size();
        for (int index=pos; pos<size; ++pos) {
            target -= candidates[pos];
            item.push_back(candidates[pos]);
            get_solution(result, item, pos, candidates, target);
            target += candidates[pos];
            item.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int> > result; 
    vector<int> item;
    
    get_solution(result, item, 0, candidates, target);
    return result;
}

int main()
{
    int array[] = {2, 3, 6, 7};
    int target = 7;
    
    vector<int> vec;
    vec.insert(vec.begin(), array, array+sizeof(array)/sizeof(int));
    for (auto i : vec)
        cout << i << ", ";
    cout << endl;
    
    vector<vector<int> > result = combinationSum(vec, target);
    cout << "size = " << result.size() << endl;
    
    for (auto v : result) {
        for (auto i : v) {
            cout << i << ", ";
        }
        cout << endl;
    }
    
    return 0;
}