vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    
    vector<pair<int, int>> sorted_array;
    for (int i=0; i<size; i++) {
        sorted_array.push_back(make_pair(nums[i], i));
    }
    sort(sorted_array.begin(), sorted_array.end(), 
         [](pair<int, int>p1, pair<int, int>p2) { return p1.first < p2.first; } );
    
    int beg = 0;
    int end = size-1;
    while (beg < end) {
        int sum = sorted_array[beg].first + sorted_array[end].first;
        
        if (sum > target) {
            end --;
        }
        else if (sum < target) {
            beg ++;
        }
        else {
            return {sorted_array[beg].second, sorted_array[end].second};
        }
    }
    return {};
}
