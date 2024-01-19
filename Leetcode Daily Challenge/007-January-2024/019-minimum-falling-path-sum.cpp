// https://leetcode.com/problems/minimum-falling-path-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[101][101];
    int solve_mem(vector<vector<int>>& matrix, int row, int col, int n) {
        if (row == n - 1) 
            return matrix[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int minSum = INT_MAX;
        int sum    = matrix[row][col];

        if (row + 1 < n && col - 1 >= 0)
            minSum = min(minSum, sum + solve_mem(matrix, row + 1, col - 1, n));
        if (row + 1 < n && col + 1 < n)
            minSum = min(minSum, sum + solve_mem(matrix, row + 1, col + 1, n));
        if (row + 1 < n)
            minSum = min(minSum, sum + solve_mem(matrix, row + 1, col, n));

        return dp[row][col] = minSum;
    }

    // TC : O(N*N)
    // SC : O(N*N)
    int solve_memoization(vector<vector<int>>& matrix) {
        int result = INT_MAX;
        int n      = matrix.size();
        int row    = 0;
        
        memset(dp, -1, sizeof(dp));

        for (int col = 0; col < n; col++) {
            result = min(result, solve_mem(matrix, row, col, n));
        }

        return result;
    }

    // TC : O(N*N)
    // SC : O(N*N)
    int solve_tabulation(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int col = 0; col < n; col++) {
            dp[0][col] = matrix[0][col];
        }
        
        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {
                dp[row][col] = matrix[row][col] + min({dp[row-1][col], 
                                                       dp[row - 1][max(0, col - 1)], 
                                                       dp[row - 1][min(n - 1, col + 1)]});
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

    // TC : O(N*N)
    // SC : O(N)
    int solve_spaceOptimization(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n);

        for(int col = 0; col < n; col++)
            prev[col] = matrix[0][col];
        
        for(int row = 1; row<n; row++) {
            vector<int> curr(n);
            for(int col = 0; col<n; col++) {
                curr[col] = matrix[row][col] + min( {prev[max(0, col - 1)],  
                                                     prev[col],  prev[min(n - 1, col + 1)]} );
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // return solve_memoization(matrix);

        // return solve_tabulation(matrix);

        return solve_spaceOptimization(matrix);
    }
};