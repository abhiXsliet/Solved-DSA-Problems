// https://leetcode.com/problems/dungeon-game/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // TC : O(M * N)
    // SC : O(M * N)
    int dfs(vector<vector<int>>& dungeon, vector<vector<int>>& memo, int i, int j) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        // If we reach the princess's cell
        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);
        }
        
        // If we go out of bounds
        if (i >= m || j >= n) {
            return INT_MAX;
        }
        
        // If the result is already computed, return it
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        // Calculate the minimum health required to move right or down
        int right = dfs(dungeon, memo, i, j + 1);
        int down = dfs(dungeon, memo, i + 1, j);
        
        // Minimum health required to enter this cell
        int min_health = min(right, down) - dungeon[i][j];
        
        // Ensure the knight has at least 1 health point
        memo[i][j] = max(1, min_health);
        
        return memo[i][j];
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_1(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        
        // Initialize memoization table with -1
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return dfs(dungeon, memo, 0, 0);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n -1]);
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1) continue;
                int right = dp[i][j + 1];
                int down  = dp[i + 1][j];
                
                // Minimum health required to enter this cell
                int min_health = min(right, down) - dungeon[i][j];
                
                // Ensure the knight has at least 1 health point
                dp[i][j] = max(1, min_health);
            }
        }

        return dp[0][0];
    }

    // TC : O(M * N)
    // SC : O(M + N)
    int approach_3(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        
        vector<int> curr(n + 1, INT_MAX), prev(n + 1, INT_MAX);
        curr[n - 1] = max(1, 1 - dungeon[m - 1][n -1]);
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1) continue;
                int right = curr[j + 1];
                int down  = prev[j];
                
                // Minimum health required to enter this cell
                int min_health = min(right, down) - dungeon[i][j];
                
                // Ensure the knight has at least 1 health point
                curr[j] = max(1, min_health);
            }
            prev = curr;
        }

        return curr[0];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // return approach_1(dungeon);
        // return approach_2(dungeon);
        return approach_3(dungeon);
    }
};