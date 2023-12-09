/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
You must decrease the overall operation steps as much as possible.

Example 1:
    Input: nums = [1,3,5]
    Output: 1

Example 2:
    Input: nums = [2,2,2,0,1]
    Output: 0
*/

class Solution {
    private int recurHelper(int[] nums, int beg, int end) {
        if (beg >= end) return nums[beg];
        if (nums[beg] < nums[end]) return nums[beg];

        int middle = beg + (end-beg)/2;
        int v1 = recurHelper(nums, beg, middle);
        int v2 = recurHelper(nums, middle+1, end);
        return v1<v2?v1:v2;
    }

    public int findMin(int[] nums) {
        int size = nums.length;
        if (size <= 1) return nums[0];
        if (size == 2) return Math.min(nums[0], nums[1]);
        if (nums[0] < nums[size-1]) return nums[0];

        int v1 = recurHelper(nums, 0, size/2);
        int v2 = recurHelper(nums, size/2+1, size-1);
        return v1<v2?v1:v2;
    }
}
