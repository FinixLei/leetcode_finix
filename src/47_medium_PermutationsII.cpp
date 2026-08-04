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

class Solution {
private:
    vector<vector<int>> result = {};
    vector<int> visited;

private:
    void print_vector(vector<int>& vec) {
        for (int i=0; i<vec.size(); i++) cout << vec[i] << " ";
        cout << endl;
    }

    void go(const vector<int>& nums, vector<int>& tmp) {
        const int size = nums.size();
        if (tmp.size() == size) {
            result.push_back(tmp);
            return;
        }
        for (int i=0; i<size; i++) {
            if (visited[i] == 1) continue;            
            visited[i] = 1;
            tmp.push_back(nums[i]);
            go(nums, tmp);
            tmp.pop_back();
            visited[i] = 0;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int size = nums.size();
        if (size == 0) return {};
        visited.resize(size);
        for (int i=0; i<size; i++) visited[i] = 0;

        vector<int> tmp{};
        sort(nums.begin(), nums.end());
        go(nums, tmp);

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};