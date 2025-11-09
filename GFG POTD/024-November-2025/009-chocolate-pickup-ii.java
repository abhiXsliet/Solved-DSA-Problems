// https://www.geeksforgeeks.org/problems/chocolate-pickup-ii/1/




class Solution {
    // TC : O(N^3)
    // SC : O(N^3)
    public int chocolatePickup(int[][] mat) {
        int n = mat.length;
        Integer[][][] dp = new Integer[n][n][n];
        int ans = solve(0, 0, 0, mat, dp);
        return Math.max(0, ans);
    }
    
    private int solve(int r1, int c1, int r2, int[][] mat, Integer[][][] dp) {
        int n = mat.length;
        int c2 = r1 + c1 - r2; // since both robots took same number of steps
        
        // boundary check
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) return (int)-1e9;
        
        // blocked cell
        if (mat[r1][c1] == -1 || mat[r2][c2] == -1) return (int)-1e9;
        
        // destination reached
        if (r1 == n - 1 && c1 == n - 1) return mat[r1][c1];
        
        if (dp[r1][c1][r2] != null) return dp[r1][c1][r2];
        
        int chocolates = 0;
        if (r1 == r2 && c1 == c2)
            chocolates = mat[r1][c1]; // same cell -> count once
        else
            chocolates = mat[r1][c1] + mat[r2][c2];
        
        int maxNext = Math.max(
            Math.max(solve(r1 + 1, c1, r2 + 1, mat, dp), solve(r1, c1 + 1, r2, mat, dp)),
            Math.max(solve(r1 + 1, c1, r2, mat, dp), solve(r1, c1 + 1, r2 + 1, mat, dp))
        );
        
        chocolates += maxNext;
        
        return dp[r1][c1][r2] = chocolates;
    }
}