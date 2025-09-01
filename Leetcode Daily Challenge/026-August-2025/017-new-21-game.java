// https://leetcode.com/problems/new-21-game/




class Solution {
    // TC : O(N)
    // SC : O(N)
    public double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;
        if (n >= k - 1 + maxPts) return 1.0;

        double[] dp = new double[n + 1];
        dp[0] = 1.0;

        double probability = 0.0;
        double windowSum   = 1.0;

        for (int i = 1; i <= n; i ++) {
            dp[i] = windowSum / maxPts;

            if (i < k) windowSum += dp[i];
            else probability += dp[i];

            if (i >= maxPts) windowSum -= dp[i - maxPts];
        }

        return probability;
    }
}