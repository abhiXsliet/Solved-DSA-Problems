// https://leetcode.com/problems/count-square-submatrices-with-all-ones/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m;
    int n;

    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if (i >= m || j >= n || matrix[i][j] == 0)
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        int right = solve(i, j + 1, matrix, dp);   
        int diag  = solve(i + 1, j + 1, matrix, dp);
        int down  = solve(i + 1, j, matrix, dp);

        return dp[i][j] = 1 + min({right, diag, down});
    }

    // TC : O(M * N) Each State will be visited only once
    // SC : O(M * N) Space used by state array
    int mem(vector<vector<int>> &matrix) {
        int result = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j]) {
                    result += solve(i, j, matrix, dp);
                }
            }
        }
        
        return result;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int tab(vector<vector<int>> &matrix) {
        // dp[i][j] : total squares (cell having 1) ending at (i, j)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int result = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                } else if (matrix[i][j]) {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
                result += dp[i][j];
            }
        }
        return result;
    }

    // TC : O(M * N)
    // SC : O(1)
    int so(vector<vector<int>> &matrix) {
        int result = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] && i > 0 && j > 0) {
                    matrix[i][j] = 1 + min({matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]});
                }
                result += matrix[i][j];
            }
        }
        return result;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        // return mem(matrix);
        // return tab(matrix);
        return so(matrix);
    }
};