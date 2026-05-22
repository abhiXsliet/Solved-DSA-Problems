// https://www.geeksforgeeks.org/problems/1s-surrounded-by-0s/1/




import java.util.*;

class Solution {
    int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    
    private void dfs(int i, int j, int[][] grid, int[][] visited) {
        visited[i][j] = 1;
        for (int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && visited[i_][j_] == 0 && grid[i_][j_] == 1) {
                dfs(i_, j_, grid, visited);
            } 
        }
    }
    int cntOnes(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        
        int[][] visited = new int[m][n];
        
        for (int i = 0; i < m; i ++) {
            if (grid[i][0] == 1) 
                dfs(i, 0, grid, visited);
            
            if (grid[i][n - 1] == 1) 
                dfs(i, n - 1, grid, visited);
        }
        
        for (int j = 0; j < n; j ++) {
            if (grid[0][j] == 1) 
                dfs(0, j, grid, visited);

            if (grid[m - 1][j] == 1) 
                dfs(m - 1, j, grid, visited);
        }
        
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                   ans ++;
                }
            }
        }
        return ans;
    }
};