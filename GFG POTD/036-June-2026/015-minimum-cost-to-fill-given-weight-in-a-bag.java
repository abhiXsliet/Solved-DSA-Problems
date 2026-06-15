// https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1/




import java.util.Arrays;

class Solution {
    int dp[][];
    private int solve(int i, int[] cost, int w) {
        if (w == 0) return 0;
        if (i >= cost.length || i + 1 > w) return Integer.MAX_VALUE;
        
        if (dp[i][w] != -1) return dp[i][w];
        
        int op1 = Integer.MAX_VALUE;
        if (cost[i] != -1) {
            int next = solve(i, cost, w - (i + 1));
            if (next != Integer.MAX_VALUE) {
                op1 = cost[i] + next;
            }
        }
        
        int op2 = solve(i + 1, cost, w);
        
        dp[i][w] = Math.min(op1, op2);
        return dp[i][w];
    }
    public int minimumCost(int[] cost, int w) {
        int n = cost.length;
        dp = new int[n + 1][w + 1];
        for (int i = 0; i < n; i ++) {
            Arrays.fill(dp[i], -1);
        }
        int ans = solve(0, cost, w);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}