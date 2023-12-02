/*
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
    Input: nums = [2,3,-2,4]
    Output: 6
    Explanation: [2,3] has the largest product 6.
    
Example 2:
    Input: nums = [-2,0,-1]
    Output: 0
    Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

// Way-1. Brute Force Solution: Correct but Performance is not good enough 
class Solution {
    public int maxProduct(int[] nums) {
        long finalResult = Integer.MIN_VALUE;
        for(int size=1; size<=nums.length; size++) {
            for (int pos=0; pos<=nums.length-size; pos++) {
                long tmp = 1;
                for (int offset=0; offset<size; offset++) {
                    tmp = tmp * nums[pos+offset]; 
                }
                if (tmp > finalResult) {
                    finalResult = tmp;
                }
            }
        }
        return (int)finalResult;
    }
}


// Way-2. O(n) Algorithm - Kadane Algorithm
class Solution {
    public int maxProduct(int[] nums) {
        long r1 = Integer.MIN_VALUE;
        long p1 = 1;
        for (int i=0; i<nums.length; i++) {
            p1 = p1 * nums[i];
            if (p1 > r1) r1 = p1;
            if (p1 == 0) p1 = 1;
        }
        
        long r2 = Integer.MIN_VALUE;
        long p2 = 1;
        for (int i=nums.length-1; i>=0; i--) {
            p2 = p2 * nums[i];
            if (p2 > r2) r2 = p2;
            if (p2 == 0) p2 = 1;
        }

        return (int)(r1>r2?r1:r2);
    }
}
