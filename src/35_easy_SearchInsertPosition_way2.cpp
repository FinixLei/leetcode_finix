int searchInsert(vector<int>& nums, int target) {
    if (target <= nums[0]) return 0;
    if (target > nums[nums.size()-1]) return nums.size();
    if (target == nums[nums.size()-1]) return nums.size()-1;
    
    auto it = lower_bound(nums.begin(), nums.end(), target);    
    if (it == nums.end()) return nums.size(); 
    return it-nums.begin();
}