// https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1




import java.util.*;

class Solution {
    int n1, n2, n3;
    int lcsOf3(String s1, String s2, String s3) {
        n1 = s1.length();
        n2 = s2.length();
        n3 = s3.length();
        
        // return approach_1(s1, s2, s3);
        return approach_2(s1, s2, s3);
    }
    
    // TC : O(N1 * N2 * N3)
    // SC : O(N1 * N2 * N3)
    int approach_2(String s1, String s2, String s3) {
        int[][][] dp = new int[n1 + 1][n2 + 1][n3 + 1];
        for (int i = n1 - 1; i >= 0; i --) {
            for (int j = n2 - 1; j >= 0; j --) {
                for (int k = n3 - 1; k >= 0; k --) {
                    int take = 0;
                    if (s1.charAt(i) == s2.charAt(j) && s2.charAt(j) == s3.charAt(k)) {
                        take = 1 + dp[i + 1][j + 1][k + 1];
                    }
                    int notTake = Math.max(dp[i + 1][j][k], Math.max(dp[i][j + 1][k], dp[i][j][k + 1]));
                    dp[i][j][k] = Math.max(take, notTake);
                }
            }
        }
        return dp[0][0][0];
    }
    
    // TC : O(N1 * N2 * N3)
    // SC : O(N1 * N2 * N3)
    int approach_1(String s1, String s2, String s3) {
        List<List<List<Integer>>> dp = new ArrayList<>();
        for (int i = 0; i <= n1; i ++) {
            List<List<Integer>> dp2 = new ArrayList<>();
            for (int j = 0; j <= n2; j ++) {
                List<Integer> dp3 = new ArrayList<>(Collections.nCopies(n3 + 1, -1));
                dp2.add(dp3);
            }
            dp.add(dp2);
        }
        
        return mem(s1, s2, s3, 0, 0, 0, dp);
    }
    
    int mem(String s1, String s2, String s3, int i, int j, int k, List<List<List<Integer>>> dp) {
        if (i >= n1 || j >= n2 || k >= n3)
            return 0;
            
        if (dp.get(i).get(j).get(k) != -1) return dp.get(i).get(j).get(k);
        
        int take = 0;
        if (s1.charAt(i) == s2.charAt(j) && s2.charAt(j) == s3.charAt(k)) {
            take = 1 + mem(s1, s2, s3, i + 1, j + 1, k + 1, dp);
        }
        
        int op1 = mem(s1, s2, s3, i + 1, j, k, dp);
        int op2 = mem(s1, s2, s3, i, j + 1, k, dp);
        int op3 = mem(s1, s2, s3, i, j, k + 1, dp);
        int notTake = Math.max(op1, Math.max(op2, op3));
        
        int res = Math.max(take, notTake);
        dp.get(i).get(j).set(k, res);
        return res;
    }
}