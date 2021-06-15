/*
    There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

    Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

    Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

    You must decrease the overall operation steps as much as possible.


    Example 1:
        Input: nums = [2,5,6,0,0,1,2], target = 0
        Output: true
*/

#include <vector>
#include <iostream>
using namespace std;

bool _search(vector<int>& nums, int beg, int end, int target)
{
    if (beg == end) {
        if (target == nums[beg]) return true;
        else return false; 
    }
    else if (beg > end) {
        return false;
    }
    
    
    if (nums[beg] <= nums[end] && (nums[beg] > target || nums[end] < target)) return false; 
    
    int mid = beg + (end - beg + 1) / 2;
    
    if (target == nums[beg] || target == nums[mid] || target == nums[end]) return true;
    
    bool result = false;
    
    result = _search(nums, beg, mid-1, target) || _search(nums, mid+1, end, target);
    
    return result; 
}

bool search(vector<int>& nums, int target) 
{
    if (nums.size() == 0) return false;
    
    int beg = 0;
    int end = nums.size() - 1;
    int mid = (end - beg + 1) / 2; 
    
    if (nums[beg] == nums[end] && nums[beg] == nums[mid]) {
        for (int i=0; i<=end; ++i) {
            if (nums[i] == target) return true;
        }
        return false;
    }
    
    return _search(nums, beg, mid-1, target) || _search(nums, mid, end, target);
}


int main()
{
    vector<int> nums; 
    int target = 0;
    bool result = false;
    
    nums = {2, 5, 6, 0, 0, 1, 2};
    cout << std::boolalpha << search(nums, 0) << endl;
    cout << std::boolalpha << search(nums, 3) << endl;
    
    nums = {1, 1, 1, 3};
    cout << std::boolalpha << search(nums, 2) << endl;
    
    return 0;
}