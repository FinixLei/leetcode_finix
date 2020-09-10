/*
    Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

    Your algorithm's runtime complexity must be in the order of O(log n).

    If the target is not found in the array, return [-1, -1].

    Example 1:

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
    Example 2:

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
*/

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void print_vec(vector<T>& vec) 
{
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int searchScope(const vector<int>& nums, int beg, int end, int target)
{
    if (beg > end) {
        return -1;
    }
    else if (beg == end) {
        if ( nums[beg] == target ) {
            return beg;
        }
        else {
            return -1;
        }
    }
    else {    // beg < end
        int mid = beg + (end-beg)/2; 
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return searchScope(nums, mid+1, end, target);
        }
        else {  // nums[mid] > target
            return searchScope(nums, beg, mid-1, target);
        }
    }
}
    

vector<int> searchRange(vector<int>& nums, int target) 
{
    int size = nums.size();
    if (size == 0) return {-1, -1};
    
    int beg = 0;
    int end = size - 1;
    
    int hit = searchScope(nums, beg, end, target);
    if (hit == -1) return {-1, -1};
    
    int min_num = hit, max_num = hit;
    while (min_num > 0) {
        if (nums[--min_num] != target) {
            min_num ++;
            break;
        }
    }
    while (max_num < size-1) {
        if (nums[++max_num] != target) {
            max_num --;
            break;
        }
    }
    
    vector<int> result{min_num, max_num};
    return result; 
}

int main()
{
    vector<int> nums;
    int target; 
    vector<int> result;
    
    nums = {5,7,7,8,8,10}; 
    target = 8; 
    result = searchRange(nums, target);
    print_vec(result);
    
    nums = {5,7,7,8,8,10}; 
    target = 6; 
    result = searchRange(nums, target);
    print_vec(result);
    
    nums = {1}; 
    target = 1; 
    result = searchRange(nums, target);
    print_vec(result);
    
    return 0;
}