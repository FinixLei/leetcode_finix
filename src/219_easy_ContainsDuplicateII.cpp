class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;
        const int size = nums.size();
        
        vector<pair<int, int>> vec;
        for (int i=0; i<size; i++) {
            vec.push_back(make_pair(nums[i], i));
        }
        sort(vec.begin(), vec.end(), [](pair<int, int>& p1, pair<int, int>& p2) { return p1.first < p2.first; });

        for (int i=0; i<size-1; i++) {
            cout << vec[i].first << ", " << vec[i+1].first << endl;
            if (vec[i].first == vec[i+1].first && abs(vec[i+1].second - vec[i].second) <= k) {
                return true;
            }
        }

        return false;
    }
};
