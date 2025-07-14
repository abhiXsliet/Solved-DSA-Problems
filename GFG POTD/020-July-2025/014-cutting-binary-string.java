// https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1




import java.util.*;

class Solution {
    private int n;
    
    public int cuts(String s) {
        n = s.length();
        
        // return approach_1(s);
        return approach_2(s);
    }

    // TC : O(N^2)
    // SC : O(N)
    private int approach_2(String s) {
        int[] dp = new int[n + 1];
        dp[n - 1] = 0;
        for (int i = n - 1; i >= 0; i --) {
            int minCuts = Integer.MAX_VALUE;
            for (int j = i; j < n; j ++) {
                if (isValidCuts(s, i, j)) {
                    int cuts = dp[j + 1];
                    if (cuts != -1) {
                        minCuts = Math.min(minCuts, 1 + cuts);
                    }
                }
            }
            dp[i] = (minCuts == Integer.MAX_VALUE) ? -1 : minCuts;
        }
        return dp[0];
    }

    // TC : O(N^2)
    // SC : O(N)
    private int approach_1(String s) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return solve(s, 0, dp);
    }
    
    private int solve(String s, int i, int[] dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int minCuts = Integer.MAX_VALUE;
        for (int j = i; j < n; j ++) {
            if (isValidCuts(s, i, j)) {
                int cuts = solve(s, j + 1, dp);
                if (cuts != -1) {
                    minCuts = Math.min(minCuts, 1 + cuts);
                }
            }
        }
        int val = (minCuts == Integer.MAX_VALUE) ? -1 : minCuts;
        dp[i] = val;
        return dp[i];
    }
    
    boolean isValidCuts(String s, int start, int end) {
        if (s.charAt(start) == '0') return false;
        int decimal = 0;
        for (int i = start; i <= end; i ++) {
            decimal = (decimal * 2) + s.charAt(i) - '0';
        }
        return isPower5(decimal);
    }
    
    boolean isPower5(int num) {
        if (num == 0) return false;
        double val = Math.log(num) / Math.log(5);
        return (Math.abs(val - Math.round(val)) < 1e-9);
    }
}