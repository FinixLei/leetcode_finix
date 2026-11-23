class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> data;
        for (auto i : nums) {
            data[i] ++;
        }
        const int threshold = nums.size() / 3;
        vector<int> res;
        for (auto item : data) {
            if (item.second > threshold) res.push_back(item.first);
        }
        return res;
    }
};
