/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0
*/


#include <iostream>
using namespace std;
#include <vector>

int searchInsert(vector<int>& nums, int target)
{
    int size = nums.size();
    if (target < nums[0]) return 0;
    if (target > nums[size-1]) return size; 
    if (target == nums[0]) return 0;
    if (target == nums[size-1]) return size-1;
    
    int start = 0;
    int end = size-1;
    while(end > start) {
        if (nums[start] < target && target < nums[end]) {
            if (end - start == 1) {
                return end; 
            }
            
            int med = (start+end)/2; 
            if (nums[med] == target) return med; 
            if (nums[med] < target) {
                start = med; 
            }
            else {  // nums[med] > target 
                end = med;
            }
        }
    }
}
