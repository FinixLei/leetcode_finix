/*
    You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
    Evaluate the expression. Return an integer that represents the value of the expression.

    Note that:
    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.
     

    Example 1:
        Input: tokens = ["2","1","+","3","*"]
        Output: 9
        Explanation: ((2 + 1) * 3) = 9
    
    Example 2:
        Input: tokens = ["4","13","5","/","+"]
        Output: 6
        Explanation: (4 + (13 / 5)) = 6
        
    Example 3:
        Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
        Output: 22
        Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
        = ((10 * (6 / (12 * -11))) + 17) + 5
        = ((10 * (6 / -132)) + 17) + 5
        = ((10 * 0) + 17) + 5
        = (0 + 17) + 5
        = 17 + 5
        = 22
*/

class Solution {
    // return an array with 2 elements which are 2 numbers' indices
    private int[] findTwoNumberIds(String[] tokens, int pos) {
        int[] result = {-1, -1};
        int count = 0;
        for (int i=pos-1; i>=0; i--) {
            if (tokens[i] != null) {
                count ++;
                if (count == 1) {
                    result[1] = i;
                }
                else if (count == 2) {
                    result[0] = i;
                    break;
                }
            }
        }
        if (result[0] == -1 || result[1] == -1) {
            throw new RuntimeException("Cannot find numbers for operator");
        }
        return result;
    }

    public int evalRPN(String[] tokens) {
        if (tokens.length == 1) {
            return Integer.parseInt(tokens[0]);
        }

        List<Integer> operatorPositions = new ArrayList<>();

        for (int i=0; i<tokens.length; i++) {
            String token = tokens[i];
            if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                operatorPositions.add(i);
            }
        }

        int result = 0;

        for (int opPos : operatorPositions) {
            int[] twoNumberIds = findTwoNumberIds(tokens, opPos);

            String op = tokens[opPos];
            int opA = Integer.parseInt(tokens[twoNumberIds[0]]);
            int opB = Integer.parseInt(tokens[twoNumberIds[1]]);

            if (op.equals("+")) {
                result = opA + opB;
            }
            else if (op.equals("-")) {
                result = opA - opB;
            }
            else if (op.equals("*")) {
                result = opA * opB;
            }
            else {  // op == "/"
                result = opA / opB;
            }

            // Replace two numbers and the opeartor with result and null-s
            tokens[twoNumberIds[0]] = Integer.toString(result);
            tokens[twoNumberIds[1]] = null;
            tokens[opPos] = null;
        }

        return result;
    }
}