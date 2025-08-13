// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/




import java.util.*;

class Solution {
    private final int M = 1_000_000_000 + 7;
    private int[][] dp;

    // TC : O(N * N)
    // SC : O(N * N)
    public int numberOfWays(int n, int x) {
        dp = new int[n + 1][n + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return solve(1, n, x);
    }

    private int solve(int val, int n, int x) {
        if (n <= 0) return (n == 0) ? 1 : 0;

        
        int power = (int) Math.pow(val, x);
        if (power > n) return 0;

        if (dp[val][n] != -1) return dp[val][n];

        int incl = solve(val + 1, n - power, x) % M;
        int excl = solve(val + 1, n, x) % M;

        int total = (incl + excl) % M;
        dp[val][n] = total;
        return total;
    }
}   