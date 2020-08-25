/*
    Given an integer array nums sorted in ascending order, and an integer target.

    Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

    You should search for target in nums and if you found return its index, otherwise return -1.

    Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    
    Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
    
    Example 3:
    Input: nums = [1], target = 0
    Output: -1
*/

#include <vector>
#include <iostream>
using namespace std;


int get_final_num_index(vector<int>& nums, int beg, int end)
{
    if (beg == end) return beg; 
    if (beg + 1 == end) {
        return nums[beg] > nums[end] ? beg : end ;
    }
    
    int result = -1;
    int mid = beg + (end - beg) / 2;
    
    if (nums[beg] <= nums[mid]) {
        if (nums[mid] > nums[mid+1]) {
            result = mid;
        }
        else {
            result = get_final_num_index(nums, mid+1, end);
        }
    }
    else {
        result = get_final_num_index(nums, beg, mid);
    }
    
    return result;
}

int binary_search(vector<int>& nums, int beg, int end, int target)
{
    if (beg > end) return -1;
    if (beg == end) {
        if (nums[beg] == target) return beg;
        else return -1;
    }
    if (beg + 1 == end) {
        if (nums[beg] == target) return beg;
        else if (nums[end] == target) return end;
        else return -1;
    }
    if (target > nums[end] || target < nums[beg]) return -1;
    
    int mid = beg + (end - beg) / 2;
    if (nums[mid] == target) return mid; 
    if (nums[mid] < target) return binary_search(nums, mid+1, end, target);
    if (nums[mid] > target) return binary_search(nums, beg, mid, target);
    return -1;
}


int search(vector<int>& nums, int target) {
    int size = nums.size();
    if (size == 0) return -1;
    if (size == 1) {
        if (nums[0] == target) 
            return 0;
        else 
            return -1;
    }
    
    int result = -1;
    int final_num_index = get_final_num_index(nums, 0, size-1);
    
    if (nums[final_num_index] < target) {
        return -1;
    }
    else {  // biggest number >= target 
        if (target < nums[0]) {
            result = binary_search(nums, final_num_index+1, size-1, target);
        }
        else {  // target >= nums[0]
            result = binary_search(nums, 0, final_num_index, target);
        }
    }
    
    return result;
}


int main()
{
    vector<int> nums;
    int target;
    int result; 
    
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    result = search(nums, target);
    // result = get_final_num_index(nums, 0, nums.size()-1);
    cout << result << endl;
    
    return 0;
}
