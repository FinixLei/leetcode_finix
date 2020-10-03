/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example 1:

    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include <vector>
#include <iostream>
using namespace std;

int maxSubArray(vector<int>& nums) 
{
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    
    int result = 0;
    int final_result = 0;
    int size = nums.size();
    int max_num = nums[0];
    int first_positive_id = -1;
    
    for (int i=0; i<size; i++) {
        if (max_num < nums[i]) {
            max_num = nums[i];
        }
        if (first_positive_id < 0 && nums[i] > 0) {
            first_positive_id = i;  // find the first positive number 
        }
    }
    
    if (max_num <= 0) {  // if max num is negative, just return it 
        return max_num;
    }
    
    int i = first_positive_id;  // start from the first positive number 
    result = nums[i++];
    final_result = result > final_result ? result : final_result; 
    
    while (i < size) {
        if (nums[i] >= 0) {
            result += nums[i];
            final_result = result > final_result ? result : final_result; 
        }
        else {  // nums[i] < 0
            if (result + nums[i] >= 0) {
                result += nums[i];
            }
            else {  // result + nums[i] < 0 , so reset all  
                result = 0;
            }
        }
        i++;
    }
    
    return final_result;
}

int main()
{
    vector<int> nums = {};
    int result = 0;
    
    nums = {-2,1}; 
    result = maxSubArray(nums);
    cout << "result = " << result << endl;
    
    nums = {-2,1,-3,4,-1,2,1,-5,4}; 
    result = maxSubArray(nums);
    cout << "result = " << result << endl;  // 6

    return 0;
}
