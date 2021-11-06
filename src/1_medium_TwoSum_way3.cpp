vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    
    multimap<int, int> cache;
    for (int i=0; i<size; i++) {
        cache.insert(make_pair(nums[i], i));
    }
    
    vector<int> result;
    vector<int> sorted_nums(nums);
    sort(sorted_nums.begin(), sorted_nums.end());
    
    int beg = 0;
    int end = size-1;
    while (beg < end) {
        int sum = sorted_nums[beg] + sorted_nums[end];
        
        if (sum > target) {
            end --;
        }
        else if (sum < target) {
            beg ++;
        }
        else {
            int r1 = cache.find(sorted_nums[beg])->second;
            int r2 = cache.find(sorted_nums[end])->second;
            
            if (r1 == r2) {
                auto iter_pairs = cache.equal_range(sorted_nums[end]);
                for (auto it=iter_pairs.first; it != iter_pairs.second; ++it) {
                    if (r2 != it->second) {
                        r2 = it->second;
                    }
                }
            }
            
            result = {r1, r2};
            break;
        }
    }
    return result;
}