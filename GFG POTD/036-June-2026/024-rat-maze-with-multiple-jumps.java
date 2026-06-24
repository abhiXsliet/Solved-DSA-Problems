// https://www.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1/




import java.util.*;

class Solution {
    
    int m, n;
    int[][] dp;
    
    public ArrayList<ArrayList<Integer>> shortestDist(int[][] mat) {
        
        m = mat.length;
        n = mat[0].length;
        
        dp = new int[m][n];
        
        for (int i = 0; i < m; i++) {
            Arrays.fill(dp[i], -1);
        }
        
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add(0);
            }
            res.add(row);
        }
        
        if (!solve(mat, res, 0, 0)) {
            ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
            ArrayList<Integer> row = new ArrayList<>();
            row.add(-1);
            ans.add(row);
            return ans;
        }
        
        return res;
    }
    
    private boolean solve(int[][] mat,
                          ArrayList<ArrayList<Integer>> res,
                          int i,
                          int j) {
        
        if (!inBoundary(i, j) || mat[i][j] == 0)
            return false;
        
        if (i == m - 1 && j == n - 1) {
            res.get(i).set(j, 1);
            dp[i][j] = 1;
            return true;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }
        
        res.get(i).set(j, 1);
        
        for (int step = 1; step <= mat[i][j]; step++) {
            
            if (solve(mat, res, i, j + step)) {
                dp[i][j] = 1;
                return true;
            }
            
            if (solve(mat, res, i + step, j)) {
                dp[i][j] = 1;
                return true;
            }
        }
        
        res.get(i).set(j, 0); // backtrack
        dp[i][j] = 0;
        
        return false;
    }
    
    private boolean inBoundary(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
}