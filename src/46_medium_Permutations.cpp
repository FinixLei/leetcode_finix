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

class Solution {
private:
    vector<vector<int>> result = {};

public:
    void go(vector<int>& nums, vector<int>& visited, vector<int>& tmp_result) {
        const int size = nums.size();
        if (tmp_result.size() == size) {
            result.push_back(tmp_result);
            return;
        }

        for (int i=0; i<size; i++) {
            if (visited[i] == 1) continue;  // find one not-visited

            visited[i] = 1;
            tmp_result.push_back(nums[i]);
            go(nums, visited, tmp_result);
            tmp_result.pop_back();
            visited[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        const int size = nums.size();
        vector<int> visited(size, 0);
        vector<int> tmp_result{};

        go(nums, visited, tmp_result);
        return result;
    }
};
