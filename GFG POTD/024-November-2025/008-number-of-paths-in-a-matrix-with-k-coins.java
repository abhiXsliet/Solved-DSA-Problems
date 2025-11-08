// https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1/




class Solution {
    int n, m;
    int[][] mat;
    Integer[][][] dp;

    public int numberOfPath(int[][] mat, int k) {
        this.n = mat.length;
        this.m = mat[0].length;
        this.mat = mat;

        // dp[i][j][k] = number of paths from (i,j) to bottom-right with sum = k
        dp = new Integer[n][m][k + 1];

        return solve(0, 0, k);
    }

    private int solve(int i, int j, int k) {
        // boundary and sum check
        if (i >= n || j >= m || k < 0) return 0;

        // reached destination
        if (i == n - 1 && j == m - 1) {
            return (k == mat[i][j]) ? 1 : 0;
        }

        // if already computed for this (i,j,k)
        if (dp[i][j][k] != null) return dp[i][j][k];

        // reduce the target sum after choosing current cell
        int remaining = k - mat[i][j];

        // explore next moves
        int down = solve(i + 1, j, remaining);
        int right = solve(i, j + 1, remaining);

        // store result
        return dp[i][j][k] = down + right;
    }
}