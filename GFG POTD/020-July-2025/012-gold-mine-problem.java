// https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1




import java.util.*;

class Solution {
    private int m, n;
    
    private int[][] directions = new int[][] {{-1, 1}, {0, 1}, {1, 1}};
    private int[][] dp;
    
    public int maxGold(int[][] mat) {
        m = mat.length;
        n = mat[0].length;
        
        // return approach_1(mat);  // used dp array for memoization
        // return approach_2(mat);  // modified input mat for memoization
        return approach_3(mat);  // tabulation
    }
    
    // TC : O(M * N)
    // SC : O(1)
    private int approach_3(int[][] mat) {
        int ans = 0;
        for (int j = n - 2; j >= 0; j --) {
            for (int i = 0; i < m; i ++) {
                
                int upperRight = 0, right = 0, downRight = 0;
                
                if (i - 1 >= 0 && j + 1 < n)
                    upperRight = Math.max(upperRight, mat[i - 1][j + 1]);
                    
                if (j + 1 < n) 
                    right = Math.max(right, mat[i][j + 1]);
                    
                if (i + 1 < m && j + 1 < n)
                    downRight = Math.max(downRight, mat[i + 1][j + 1]);
                    
                mat[i][j] += Math.max(upperRight, Math.max(right, downRight));
                
                ans = Math.max(ans, mat[i][j]);
            }
        }
        return ans;
    }
    
    // TC : O(M * N)
    // SC : O(1)
    private int approach_2(int[][] mat) {
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            ans = Math.max(ans, dfsOptimized(mat, i, 0));
        }
        return ans;
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    private int approach_1(int[][] mat) {
        int ans = 0;
        dp = new int[m + 1][n + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        for (int i = 0; i < m; i ++) {
            ans = Math.max(ans, dfs(mat, i, 0));
        }
        return ans;
    }
    
    
    private int dfs(int[][] mat, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        
        int original = mat[i][j];
        mat[i][j] = -1; // visited
        
        int maxNext = 0;
        for (int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (isValid(i_, j_) && mat[i_][j_] != -1) {
                maxNext = Math.max(maxNext, dfs(mat, i_, j_));
            }
        }
        
        mat[i][j] = original;
        dp[i][j] = maxNext + original;
        return dp[i][j];
    }
    
    private int dfsOptimized(int[][] mat, int i, int j) {
        if (mat[i][j] < 0) return -mat[i][j];
        
        int original = mat[i][j];
        
        int maxNext = 0;
        for (int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (isValid(i_, j_) && mat[i_][j_] != -1) {
                maxNext = Math.max(maxNext, dfsOptimized(mat, i_, j_));
            }
        }
        
        mat[i][j] = -(maxNext + original);
        return Math.abs(mat[i][j]);
    }
    
    private boolean isValid(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
}