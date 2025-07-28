// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/




import java.util.*;

class Solution {
    // TC : O(N * maxOr)
    // SC : O(N * maxOr)
    public int countMaxOrSubsets(int[] nums) {
        int maxOr = 0;
        for (int num : nums) maxOr |= num;

        int[][] dp = new int[nums.length + 1][maxOr + 1];
        for (int i = 0; i < dp.length; i ++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(0, 0, nums, maxOr, dp);
    }
    private int solve(int i, int currOr, int[] nums, int maxOr, int[][] dp) {
        if (i >= nums.length) {
            if (currOr == maxOr)
                return 1;
            return 0;
        }

        if (dp[i][currOr] != -1) return dp[i][currOr];

        int op1 = solve(i + 1, currOr | nums[i], nums, maxOr, dp);
        int op2 = solve(i + 1, currOr, nums, maxOr, dp);

        dp[i][currOr] = (op1 + op2);
        return dp[i][currOr];
    }
}