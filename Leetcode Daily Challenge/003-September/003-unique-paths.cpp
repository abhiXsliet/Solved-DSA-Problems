// https://leetcode.com/problems/unique-paths/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N*M)
    // SC = O(N*M)
    int solveMem(int i, int j, int m, int n, vector<vector<int>>& dp) {
        // base case
        if (i == m - 1 && j == n - 1) return 1;
        if (i >= m || j >= n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = solveMem(i+1, j, m, n, dp);
        int down = solveMem(i, j+1, m, n, dp);

        return dp[i][j] = down + right;
    }

    // TC = O(N*M)
    // SC = O(N*M)
    int solveTab(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Analyse base case
        // Initialize the value for rightmost column
        for (int i = 0; i < m; i++) {
            dp[i][n-1] = 1;
        }
        // Initialize the value for bottom row
        for (int i = 0; i < n; i++) {
            dp[m-1][i] = 1;
        }

        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                int right = dp[i+1][j];
                int down  = dp[i][j+1];

                dp[i][j] = down + right;
            }
        }
        return dp[0][0];
    }

    // TC = O(N*M)
    // SC = O(N)
    int solveSO(int m, int n) {
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        // Analyse base case
        // Initialize the value for rightmost column
        for (int i = 0; i < m; i++) {
            curr[n-1] = 1;
        }
        // Initialize the value for bottom row
        for (int i = 0; i < n; i++) {
            next[i] = 1;
        }

        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                int right = next[j];
                int down  = curr[j+1];

                curr[j] = down + right;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int uniquePaths(int m, int n) {
        // // Recursion + Memoization
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solveMem(0, 0, m, n, dp);


        // // Tabulation
        // return solveTab(m, n);


        // Space - Optimization
        return solveSO(m, n);
    }
};