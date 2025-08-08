// https://leetcode.com/problems/soup-servings/




import java.util.*;

class Solution {
    private final int[][] serves = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    private double[][] dp;

    public double soupServings(int n) {
        if (n >= 5000) return 1.0;

        dp = new double[n + 1][n + 1];
        for (double[] row : dp) {
            Arrays.fill(row, -1.0);
        }
        return probA(n, n);    
    }

    private double probA(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (dp[A][B] != -1.0) return dp[A][B];

        double totalProb = 0.0;
        for (int[] serve : serves) {
            int takenA = serve[0];
            int takenB = serve[1];

            totalProb += probA(A - takenA, B - takenB);
        }
        dp[A][B] = (0.25 * totalProb);
        return dp[A][B];
    }
}