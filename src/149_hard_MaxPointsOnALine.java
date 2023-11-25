/**
 *   Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
 *   Example 1:
 *       Input: points = [[1,1],[2,2],[3,3]]
 *       Output: 3
 * 
 *   Example 2:
 *       Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 *       Output: 4
**/

class Solution {
    public int maxPoints(int[][] points) {
        if (points.length == 0) return 0;
        if (points.length == 1) return 1;
        int size = points.length;

        int maxNum = 0;

        for (int i=0; i<size-1; i++) {
            for (int j=i+1; j<size; j++) {
                if (i == j) continue;

                // Two points determine one line, then check how many nodes are on this line
                // Point A is points[i], Point B is points[j]

                double slope = 1.0*(points[j][1]- points[i][1])/(points[j][0]-points[i][0]);
                int number = 1; // A and B form one line

                for (int k=0; k<size; k++) {
                    if (i==k || i==j) continue;
                    double currentSlope = 1.0*(points[k][1]-points[i][1])/(points[k][0]-points[i][0]);
                    if (currentSlope == slope) {
                        number ++;
                    }
                }
                if (number > maxNum) {
                    maxNum = number;
                }
            }
        }
        return maxNum;
    }
}
