// https://www.geeksforgeeks.org/problems/special-keyboard3018/1/




class Solution {
    public int optimalKeys(int n) {

        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; i++) {

            // press A
            dp[i] = dp[i - 1] + 1;

            // try copy-paste strategy
            for (int j = 1; j <= i - 3; j++) {

                dp[i] = Math.max(
                    dp[i],
                    dp[j] * (i - j - 1)
                );
            }
        }

        return dp[n];
    }
}