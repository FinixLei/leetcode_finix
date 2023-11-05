/*
    There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

    You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.
    Return the minimum number of candies you need to have to distribute the candies to the children.

    Example 1:
        Input: ratings = [1,0,2]
        Output: 5
        Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
    
    Example 2:
        Input: ratings = [1,2,2]
        Output: 4
        Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
        The third child gets 1 candy because it satisfies the above two conditions.
*/


class Solution {
    private void print_list(int[] list) {
        for (int i : list) {
            System.out.print(i + ", ");
        }
        System.out.println();
    }
    public int candy(int[] ratings) {
        int size = ratings.length;

        int[] result = new int [size];
        for (int i=0; i<size; i++) {
            result[i] = 1;
        }

        for (int i=0; i<size-1; i++) {
            if (ratings[i] < ratings[i+1]) {
                result[i+1] = result[i]+1 > result[i+1] ? (result[i]+1) : result[i+1];
            }
        }

        for (int i=size-1; i>=1; i--) {
            if (ratings[i] < ratings[i-1]) {
                result[i-1] = result[i]+1 > result[i-1] ? (result[i]+1) : result[i-1];
            }
        }

        int sum = 0;
        for (int i : result) {
            sum += i;
        }
        return sum;
    }
}
