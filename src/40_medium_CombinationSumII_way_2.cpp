class Solution {
private:
    vector<vector<int>> result = {};

private:
    // return true, no need to use later candidates; false, need to test later candidates.
    void solve(vector<int>& candidates, int target, vector<int>& curr_vec, int pos) {
        int sum = accumulate(curr_vec.begin(), curr_vec.end(), 0);

        if (sum == target) {
            result.push_back(curr_vec);
            return;
        }
        else if (sum > target) {
            return;
        }

        for (int i=pos; i < candidates.size(); i++) {
            curr_vec.push_back(candidates[i]);
            solve(candidates, target, curr_vec, i+1);
            curr_vec.pop_back();
            // This is the key to remove the redundant
            while (i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        }
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr_vec = {};
        solve(candidates, target, curr_vec, 0);
        return result;
    }
};