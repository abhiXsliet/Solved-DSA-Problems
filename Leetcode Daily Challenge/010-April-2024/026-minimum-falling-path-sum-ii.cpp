// https://leetcode.com/problems/minimum-falling-path-sum-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC (Recursive) : O(N * N^N) for every col of 1st row, we have (n^n) possibility
    // SC (Recursive) : O(N) -> Depth of Recursion

    // TC : O(N * (N * N)) for every col of 1st row, we're traversing whole grid
    // SC : O(N * N)
    int solve_mem(int col, int row, vector<vector<int>>& grid, int n, vector<vector<int>>& dp) {
        if (row == n - 1) return grid[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int ans = INT_MAX;
        for (int newCol = 0; newCol < n; newCol ++) {
            if (newCol != col) {
                ans = min(ans, solve_mem(newCol, row + 1, grid, n, dp));
            }
        }
        return dp[row][col] = ans + grid[row][col];
    }

    // TC : O(N^3)
    // SC : O(N^2)
    int approach_1(vector<vector<int>>& grid) {
        int n = grid.size();
        int row = 0;
        int result = INT_MAX;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int col = 0; col < n; col ++) {
            result = min(result, solve_mem(col, row, grid, n, dp));
        }
        return result;
    }

    
    // TC : O(N^3)
    // SC : O(N^2)
    int approach_2(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int col = n - 1; col >= 0; col --) {
            dp[n - 1][col] = grid[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row --) {
            for (int col = 0; col < n; col ++) {
                int val = INT_MAX;
                for (int newCol = 0; newCol < n; newCol ++) {
                    if (col != newCol) {  
                        val = min(val, dp[row + 1][newCol]);
                    }
                }
                dp[row][col] = grid[row][col] + val;
            }
        }
        int result = INT_MAX;
        for (int col = 0; col < n; col ++) {
            result = min(result, dp[0][col]);
        }
        return result;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int approach_3(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int nextMinCol1 = -1;   // store col idx of 1st min value in row + 1
        int nextMinCol2 = -1;   // store col idx of 2nd min value in row + 1

        for (int col = n - 1; col >= 0; col --) {
            dp[n - 1][col] = grid[n - 1][col];

            if (nextMinCol1 == -1 || dp[n - 1][col] <= dp[n - 1][nextMinCol1]) {
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = col;
            }
            else if (nextMinCol2 == -1 || dp[n - 1][col] <= dp[n - 1][nextMinCol2]){
                nextMinCol2 = col;
            }
        }

        for (int row = n - 2; row >= 0; row --) {
            int minCol1 = -1;
            int minCol2 = -1;
            for (int col = 0; col < n; col ++) {

                if (col != nextMinCol1) {
                    dp[row][col] = grid[row][col] + dp[row + 1][nextMinCol1];
                }
                else {
                    dp[row][col] = grid[row][col] + dp[row + 1][nextMinCol2];
                }

                if (minCol1 == -1 || dp[row][col] <= dp[row][minCol1]) {
                    minCol2 = minCol1;
                    minCol1 = col;
                }
                else if (minCol2 == -1 || dp[row][col] <= dp[row][minCol2]) {
                    minCol2 = col;
                }
            }
            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
        }

        // int result = INT_MAX;
        // for (int col = 0; col < n; col ++) {
        //     result = min(result, dp[0][col]);
        // }
        // return result;

        return dp[0][nextMinCol1];
    }

    // TC : O(N^2)
    // SC : O(1)
    int approach_4(vector<vector<int>>& grid) {
        int n = grid.size();

        int nextMinCol1 = -1;   // store col idx of 1st min value in row + 1
        int nextMinCol2 = -1;   // store col idx of 2nd min value in row + 1

        for (int col = n - 1; col >= 0; col --) {
            if (nextMinCol1 == -1 || grid[n - 1][col] <= grid[n - 1][nextMinCol1]) {
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = col;
            }
            else if (nextMinCol2 == -1 || grid[n - 1][col] <= grid[n - 1][nextMinCol2]){
                nextMinCol2 = col;
            }
        }

        for (int row = n - 2; row >= 0; row --) {
            int minCol1 = -1;
            int minCol2 = -1;
            for (int col = 0; col < n; col ++) {

                if (col != nextMinCol1) {
                    grid[row][col] += grid[row + 1][nextMinCol1];
                }
                else {
                    grid[row][col] += grid[row + 1][nextMinCol2];
                }

                if (minCol1 == -1 || grid[row][col] <= grid[row][minCol1]) {
                    minCol2 = minCol1;
                    minCol1 = col;
                }
                else if (minCol2 == -1 || grid[row][col] <= grid[row][minCol2]) {
                    minCol2 = col;
                }
            }
            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
        }

        return grid[0][nextMinCol1];
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // return approach_1(grid);    // memoization

        // return approach_2(grid);    // Tabulation

        // return approach_3(grid);    // Tabulation better

        return approach_4(grid);       // Space Optimized
    }
};