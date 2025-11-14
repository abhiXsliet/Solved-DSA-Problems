// https://www.geeksforgeeks.org/problems/minimum-cost-to-merge-stones/1/




class Solution {
    public static int mergeStones(int[] stones, int k) {
        int n = stones.length;

        // Feasibility check
        if ((n - 1) % (k - 1) != 0) return -1;

        // prefix sum
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];

        // dp[i][j][t] = min cost to merge stones[i..j] into t piles
        int[][][] dp = new int[n][n][k + 1];

        // initialize
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int t = 0; t <= k; t++)
                    dp[i][j][t] = Integer.MAX_VALUE / 2;

        // Single pile: cost 0
        for (int i = 0; i < n; i++)
            dp[i][i][1] = 0;

        // interval DP length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                // compute dp[i][j][t] for t=2..k
                for (int t = 2; t <= k; t++) {

                    for (int m = i; m < j; m += (k - 1)) {
                        if (dp[i][m][1] < Integer.MAX_VALUE / 2 
                            && dp[m + 1][j][t - 1] < Integer.MAX_VALUE / 2) {

                            dp[i][j][t] = Math.min(
                                dp[i][j][t],
                                dp[i][m][1] + dp[m + 1][j][t - 1]
                            );
                        }
                    }
                }

                // finally compute dp[i][j][1]
                if (dp[i][j][k] < Integer.MAX_VALUE / 2) {
                    dp[i][j][1] = dp[i][j][k] + (prefix[j + 1] - prefix[i]);
                }
            }
        }

        return dp[0][n - 1][1];
    }
}