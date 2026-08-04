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
            // 核心：去重，在同层中，若前一个是相同的数，且没有被用过，则当前数就不用了，因为同层在之前一定会用第一个相同数
            if (i >= 1 && nums[i] == nums[i-1] && visited[i-1] == 0) continue;  
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
        
        return result;
    }
};