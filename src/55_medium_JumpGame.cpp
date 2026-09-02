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

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int max_pos = nums.size() - 1;
        int pos = 0;
        int max_reach = -1;
        while (true) {
            max_reach = max(max_reach, pos + nums[pos]);
            if (max_reach >= max_pos) return true;
            if (pos + 1 <= max_reach) pos ++;
            else return false;
        }
        return false;
    }
};
