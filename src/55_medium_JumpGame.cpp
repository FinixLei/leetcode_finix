/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

#include <iostream>
using namespace std;


bool canJump(vector<int>& nums) 
{
    if (nums.size() == 0) return false; 
    
    int last_index = nums.size() - 1;
    int beg = 0, end = nums[0];
    
    while ( beg <= end ) {
        int current_end = beg + nums[beg]; 
        if (current_end >= last_index) return true;
        if (end < current_end) end = current_end;
        beg++;
    }
    return false;
}


int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << (canJump(nums) ? "Yes" : "No") << endl;
    
    nums = {3,2,1,0,4};
    cout << (canJump(nums) ? "Yes" : "No") << endl;
    
    return 0;
}
