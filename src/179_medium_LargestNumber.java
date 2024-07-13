/* 
  Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
  Since the result may be very large, so you need to return a string instead of an integer.

  Example 1:
  Input: nums = [10,2]
  Output: "210"
  
  Example 2:
  Input: nums = [3,30,34,5,9]
  Output: "9534330"
*/

class Solution {
    class MyComparator implements Comparator<String> {
        @Override
        public int compare(String s1, String s2) {
            String r1 = s1 + s2;
            String r2 = s2 + s1; 
            return -r1.compareTo(r2);
        }
    }

    public String largestNumber(int[] nums) {
        List<String> strNums = new ArrayList<>();
        for (int i=0; i<nums.length; i++) {
            strNums.add(new Integer(nums[i]).toString());
        }
        Collections.sort(strNums, new MyComparator());
        String result = strNums.stream()
                        .collect(Collectors.joining(""));
        
        // check all zero
        int length = result.length();
        int count = 0;
        for (int i=0; i<length; i++) {
            if (result.charAt(i) == '0') count ++;
            else break;
        }
        if (count == length) return "0";
        return result;
    }
}
