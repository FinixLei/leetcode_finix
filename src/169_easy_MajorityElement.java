/*
  Given an array nums of size n, return the majority element.
  The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

  Example 1:
  Input: nums = [3,2,3]
  Output: 3

  Example 2:
  Input: nums = [2,2,1,1,1,2,2]
  Output: 2
*/

class Solution {
    public int majorityElement(int[] nums) {
        int targetNumber = nums.length / 2;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            if (map.containsKey(i)) {
                int tmp = map.get(i) + 1;
                if (tmp > targetNumber) return i;
                map.put(i, tmp);
            }
            else {
                map.put(i, 1);
            }
            if (map.get(i) > targetNumber) return i;
        }
        return -1;
    }
}