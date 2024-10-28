// https://leetcode.com/problems/maximal-square/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m;
    int n;

    int solve(vector<vector<char>>& mat, int i, int j, vector<vector<int>> &dp) {
        if (i >= m || j >= n || mat[i][j] == '0') return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(mat, i, j + 1, dp);
        int diag  = solve(mat, i + 1, j + 1, dp);
        int down  = solve(mat, i + 1, j, dp); 

        return dp[i][j] = 1 + min({right, diag, down});
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int mem(vector<vector<char>>& mat) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int maxSide = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == '1') {
                    maxSide = max(maxSide, solve(mat, i, j, dp)); 
                }
            }
        }
        return maxSide * maxSide;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int tab(vector<vector<char>>& mat) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int maxSide = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = mat[i][j] - '0';
                } else if (mat[i][j] == '1') {
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]});
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
        return maxSide * maxSide;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        // return mem(matrix);
        return tab(matrix);
    }
};