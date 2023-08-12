// https://leetcode.com/problems/unique-paths-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(2^m+n)
    // SC = O(m+n) -> due to recursive call stack
    int solveRec(vector<vector<int>>& obstacleGrid, 
                int m, int n, int i, int j ) {
        // base case
        if ( i >= m || j >= n || obstacleGrid[i][j] == 1)
            return 0;

        if (i == m-1 && j == n - 1)
            return 1;

        int right = solveRec(obstacleGrid, m, n, i, j+1);
        int down = solveRec(obstacleGrid, m, n, i+1, j);

        return right + down;
    }

    // TC = O(m*n) 
    // SC = 0(m*n)
    int solveMem(vector<vector<int>>& obstacleGrid, 
                int m, int n, int i, int j, vector<vector<int>>& dp) {
        // base case
        if ( i >= m || j >= n || obstacleGrid[i][j] == 1)
            return 0;

        if (i == m-1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1) 
            return dp[i][j];

        int right = solveMem(obstacleGrid, m, n, i, j+1, dp);
        int down = solveMem(obstacleGrid, m, n, i+1, j, dp);

        return dp[i][j] = right + down;
    }

    // TC = O(m*n) 
    // SC = 0(m*n)
    int solveTab(vector<vector<int>>& obstacleGrid, int m, int n) {
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));

        for(int i = m - 1;  i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                
                // After Analyzing Base Case
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if(i == m - 1 && j == n - 1) 
                    dp[i][j] = 1;
                else {
                    long long right = dp[i][j+1];
                    long long down = dp[i+1][j];
                    dp[i][j] = right + down;
                }
                
            }
        }
        return dp[0][0];
    }

    // TC = O(m*n) 
    // SC = 0(n)
    int solveSO(vector<vector<int>>& obstacleGrid, int m, int n) {
        vector<long long> curr(n+1, 0);
        vector<long long> next(n+1, 0);

        for(int i = m - 1;  i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                
                // After Analyzing Base Case
                if(obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else if(i == m - 1 && j == n - 1) 
                    curr[j] = 1;
                else {
                    long long right = curr[j+1];
                    long long down = next[j];
                    curr[j] = right + down;
                }
                
            }
            next = curr;
        }
        return next[0];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // Recursive Solution -> TLE
        // return solveRec(obstacleGrid, m, n, 0, 0);

        // // Recursion + Memoization
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solveMem(obstacleGrid, m, n, 0, 0, dp);

        // Tabulation
        // return solveTab(obstacleGrid, m, n);

        // Space-Optimization
        return solveSO(obstacleGrid, m, n);
    }
};