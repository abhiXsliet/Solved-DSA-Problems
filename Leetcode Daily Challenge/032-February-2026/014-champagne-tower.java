// https://leetcode.com/problems/champagne-tower/




import java.util.*;

class Solution {
    private double[][] dp;
    public double champagneTower(int poured, int query_row, int query_glass) {
        dp = new double[query_row + 1][query_glass + 1];
        for (double[] row : dp) {
            Arrays.fill(row, -1.0);
        }
        return Math.min(1.0, mem(poured, query_row, query_glass));
    }
    private double mem(int pour, int i, int j) {
        if (i < 0 || j < 0 || i < j)
            return 0.0;

        if (i == 0 && j == 0)
            return (double)pour;

        if (dp[i][j] != -1.0)
            return dp[i][j];

        double leftUp  = (mem(pour, i - 1, j) - 1) / 2.0;
        double rightUp = (mem(pour, i - 1, j - 1) - 1) / 2.0;

        if (leftUp < 0)  leftUp  = 0.0;
        if (rightUp < 0) rightUp = 0.0;

        dp[i][j] = (leftUp + rightUp);
        return dp[i][j];
    }
}