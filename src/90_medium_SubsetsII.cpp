/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
    Input: nums = [0]
    Output: [[],[0]]
*/

class Solution {
public:
    void print_vec(vector<int>& vec) {
        for (auto i : vec) cout << i << " ";
        cout << endl;
    }
    
    void _fill(vector<int>& nums, int k, int beg, vector<int>& one_result, vector<vector<int>>& result, vector<int>& visited) {
        if (k==0) {
            result.push_back(one_result);
            return;
        }
        
        for (int i=beg; i<nums.size(); i++) {        
            if (visited[i]) continue;
            visited[i] = 1;
            one_result.push_back(nums[i]);
            _fill(nums, k-1, i+1, one_result, result, visited);
            one_result.pop_back();
            visited[i] = 0;
        }
    }
    
    void fillVecNSize(vector<int>& nums, int n, vector<vector<int>>& result) {
        vector<int> visited(nums.size(), 0);
        vector<int> one_result;
        one_result.reserve(n);
        _fill(nums, n, 0, one_result, result, visited);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) return {};
        
        vector<vector<int>> result = {{}};
        
        for (int n=1; n<=nums.size(); n++) {
             fillVecNSize(nums, n, result);
        }
       
        for (auto& vec : result) sort(vec.begin(), vec.end());
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
                
        return result;
    }
};