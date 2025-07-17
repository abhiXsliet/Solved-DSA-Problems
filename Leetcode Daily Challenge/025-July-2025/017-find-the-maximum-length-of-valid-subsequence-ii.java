// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/




class Solution {
    // TC : O(N * N)
    // SC : O(K * N)
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] dp = new int[k][n];
        int maxLen = Integer.MIN_VALUE;
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                int mod    = (nums[i] + nums[j]) % k;
                dp[mod][i] = Math.max(dp[mod][i], 1 + dp[mod][j]);
                maxLen     = Math.max(maxLen, dp[mod][i]);
            }
        }
        return (maxLen + 1);
    }   
}