// https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/




class Solution {
    private int n, m;
    private final int[][] directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    private int[][][][] t;

    // TC : O(M * N)
    // SC : O(M * N)
    public int lenOfVDiagonal(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        t = new int[m][n][4][2];
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                for (int k = 0; k < 4; k ++) {
                    for (int l = 0; l < 2; l ++) {
                        t[i][j][k][l] = -1;
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d ++) {
                        result = Math.max(result, 1 + solve(grid, i, j, d, 1, 2));
                    }
                }
            }
        }
        return result;
    }

    private int solve(int[][] grid, int i, int j, int d, int canTurn, int val) {
        int i_ = i + directions[d][0];
        int j_ = j + directions[d][1];

        if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != val)
            return 0;

        if (t[i_][j_][d][canTurn] != -1)
            return t[i_][j_][d][canTurn];

        int nextVal = (val == 2) ? 0 : 2;

        int noTurnDist = 1 + solve(grid, i_, j_, d, canTurn, nextVal);

        if (canTurn == 1) {
            int turnDist = 1 + solve(grid, i_, j_, (d + 1) % 4, 0, nextVal);
            noTurnDist   = Math.max(noTurnDist, turnDist);
        }

        return t[i_][j_][d][canTurn] = noTurnDist;
    }
}