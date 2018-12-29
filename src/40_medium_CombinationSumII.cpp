#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


void find_solutions(vector<vector<int>>& res, int target, vector<int>& candidates, int pos, vector<int>& solution)
{
    int i = pos;
    while (i < candidates.size()) {
        solution.push_back(candidates[i]);
        int t = target - candidates[i];
        if (t == 0) {
            res.push_back(solution);
        }
        else if (t > 0) {
            find_solutions(res, t, candidates, i+1, solution);
        }
        else { // t<0, no need to try later figures
            solution.pop_back();
            return;
        }
        solution.pop_back();
        i++;
        while (candidates[i] == candidates[i-1] && i < candidates.size()) i++;
    }
}


vector<vector<int> > combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    
    vector<vector<int>> result;
    vector<int> solution; 
    find_solutions(result, target, candidates, 0, solution);
    return result;
}


int main()
{
    int target = 7;
    int array_candidates[] = {10,1,1,2,2,5,7,6,6,6,1,5};
    // int array_candidates[] = {2,5,2,1,2};
    
    vector<int> candidates(array_candidates, array_candidates+sizeof(array_candidates)/sizeof(int));

    vector<vector<int>> result = combinationSum2(candidates, target);
    for (auto vec : result) {
        for (auto i : vec) {
            cout << i << ", "; 
        }
        cout << endl;
    }
    
    return 0;
}