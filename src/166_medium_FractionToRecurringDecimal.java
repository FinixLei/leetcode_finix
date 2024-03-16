/*
  Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
  If the fractional part is repeating, enclose the repeating part in parentheses.
  If multiple answers are possible, return any of them.
  It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

  Example 1:
  Input: numerator = 1, denominator = 2
  Output: "0.5"

  Example 2:
  Input: numerator = 2, denominator = 1
  Output: "2"

  Example 3:
  Input: numerator = 4, denominator = 333
  Output: "0.(012)"
*/

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        long a = numerator, b = denominator;
        boolean positive = (a>=0 && b>0) || (a<=0 && b<0);
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        long c = a / b; 
        long r = a - b * c;
        if (r == 0) {
            return positive ? Long.toString(c) : "-" + Long.toString(c);
        } 

        int index = 0;
        List<Long> quotientList = new ArrayList<>(List.of(c));
        Map<Long, Integer> remainderMap = new HashMap<>(Map.of(r, index));  // r -> index of c

        while (true) {
            a = r * 10;
            c = a / b;
            r = a - b * c;
            quotientList.add(c);
            index ++;
            if (r == 0 || remainderMap.containsKey(r)) break;
            remainderMap.put(r, index);
        }

        StringBuilder sb = new StringBuilder();
        if (!positive) sb.append("-");
        sb.append(Long.toString(quotientList.get(0)))
          .append(".");
    
        int firstLoopRemainderIndex = -1;
        if (r != 0) {
            firstLoopRemainderIndex = remainderMap.get(r);
            if (firstLoopRemainderIndex == 0) {
                sb.append("(");
            }
        }
        for(int i=1; i<quotientList.size(); i++) {
            sb.append(Long.toString(quotientList.get(i)));
            if (i == firstLoopRemainderIndex) {
                sb.append("(");
            }
        }
        if (r!=0) sb.append(")");
        return sb.toString();
    }
}