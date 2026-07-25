class Solution {
public:
    void find_solutions(vector<vector<int>>& res, int target, vector<int>& candidates, int pos, vector<int>& solution) {
        const int size = candidates.size();
        int i = pos;
        while (i < size) {
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
            while (i < size && candidates[i] == candidates[i-1]) {
                i++;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
    
        vector<vector<int>> result;
        vector<int> solution = {}; 
        find_solutions(result, target, candidates, 0, solution);
        return result;
    }
};