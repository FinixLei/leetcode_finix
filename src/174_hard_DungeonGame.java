/*
  The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
  The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
  Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
  To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
  Return the knight's minimum initial health so that he can rescue the princess.
  Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

  Example 1:
    Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
    Output: 7
    Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
  
  Example 2:
    Input: dungeon = [[0]]
    Output: 1
*/

class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int rows = dungeon.length;
        int cols = dungeon[0].length;

        // grid value means when reach this grid how much life value is needed at least
        int[][] limit = new int[rows][cols];  
        limit[rows-1][cols-1] = 1;
        if (dungeon[rows-1][cols-1] < 0) {
            limit[rows-1][cols-1] -= dungeon[rows-1][cols-1];
        }
        for (int i=rows-2; i>=0; i--) {
            limit[i][cols-1] = limit[i+1][cols-1] - dungeon[i][cols-1];
            if (limit[i][cols-1] < 1) limit[i][cols-1] = 1;
        }
        for (int i=cols-2; i>=0; i--) {
            limit[rows-1][i] = limit[rows-1][i+1] - dungeon[rows-1][i];
            if (limit[rows-1][i] < 1) limit[rows-1][i] = 1;
        }
        for (int i=rows-2; i>=0; i--) {
            for (int j=cols-2; j>=0; j--) {
                limit[i][j] = Math.min(limit[i+1][j], limit[i][j+1]) - dungeon[i][j];
                if (limit[i][j] < 1) limit[i][j] = 1;
            }
        }
        return limit[0][0];
    }
}
