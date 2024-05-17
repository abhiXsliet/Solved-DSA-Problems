// https://leetcode.com/contest/weekly-contest-397/problems/maximum-difference-score-in-a-grid/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * N)
    // SC : O(M * N)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for (int c = n - 2; c >= 0; c --) {
            dp[m - 1][c] = max(grid[m - 1][c], dp[m - 1][c + 1]);
        }

        for (int r = m - 2; r >= 0; r --) {
            dp[r][n - 1] = max(grid[r][n - 1], dp[r + 1][n - 1]);
        }

        for (int r = m - 2; r >= 0; r --) {
            for (int c = n - 2; c >= 0; c --) {
                dp[r][c] = max(grid[r][c], max(dp[r + 1][c], dp[r][c + 1]));            
            }
        }

        int ans = INT_MIN;
        for (int r = 0; r < m; r ++) {
            for (int c = 0; c < n; c ++) {
                if (r + 1 < m) ans = max(ans, dp[r + 1][c] - grid[r][c]);
                if (c + 1 < n) ans = max(ans, dp[r][c + 1] - grid[r][c]);
            }
        }
        return ans;
    }
public:
    int maxScore(vector<vector<int>>& grid) {
        return approach_1(grid);    // Tabulation
    }
};