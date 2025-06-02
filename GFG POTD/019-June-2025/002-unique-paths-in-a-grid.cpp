// https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int m, n;
    vector<vector<int>> directions {{0, 1}, {1, 0}};
    
    
    int mem(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j) {
        if (i >= m || j >= n || grid[i][j])
            return 0;
        
        if (i == m - 1 && j == n - 1)
            return 1;
            
        if (dp[i][j] != -1) return dp[i][j];
            
        int right = mem(grid, dp, i, j + 1);
        int down  = mem(grid, dp, i + 1, j);
        
        return dp[i][j] = (right + down);
    }
    
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j) {
        if (i == m - 1 && j == n - 1)
            return 1;
            
        if (dp[i][j] != -1) return dp[i][j];
            
        int ways = 0;
        for (auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !grid[i_][j_]) {
                ways += dfs(grid, dp, i_, j_);
            }
        }
        return dp[i][j] = ways;
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    int approach_1(vector<vector<int>> &grid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(grid, dp, 0, 0);
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(vector<vector<int>> &grid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return mem(grid, dp, 0, 0);
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    int approach_3(vector<vector<int>> &grid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                // Skip if current cell is blocked or it's the target cell (already set)
                if (grid[i][j] == 1 || (i == m - 1 && j == n - 1))
                    continue;
    
                // Number of paths from (i, j) = paths from below + paths from right
                int down  = (i + 1 < m) ? dp[i + 1][j] : 0;
                int right = (j + 1 < n) ? dp[i][j + 1] : 0;
                dp[i][j]  = down + right;
            }
        }
        return dp[0][0];
    }
    
    // TC : O(M * N)
    // SC : O(N)
    int approach_4(vector<vector<int>> &grid) {
        vector<int> curr(n, 0), prev(n, 0);
        prev[n - 1] = 1;
    
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    curr[j] = 0;  // Blocked cell
                } else if (i == m - 1 && j == n - 1) {
                    // Keep target cell as already set
                    curr[j] = prev[j];
                } else {
                    int down = (i + 1 < m) ? prev[j] : 0;
                    int right = (j + 1 < n) ? curr[j + 1] : 0;
                    curr[j] = down + right;
                }
            }
            prev = curr;
        }
    
        return prev[0];
    }
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        if (grid[0][0]) return 0;
        
        // return approach_1(grid);     // DFS
        // return approach_2(grid);     // Memoization
        // return approach_3(grid);     // Tabulation
        return approach_4(grid);     // SpaceOpt
    }
};