// https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*M*10)
    // SC : O(M*10)
    int solve(vector<vector<int>>& grid, int m, int n, int col, int val, vector<vector<int>>& dp) {
        if (col >= n) return 0;

        if (dp[col][val] != -1) return dp[col][val];

        int ans = INT_MAX, cost = 0;
        for (int row = 0; row < m; row ++) {
            cost += (grid[row][col] != val);
        }

        for (int option = 0; option <= 9; option ++) {
            if (option != val) {
                ans = min(ans, cost + solve(grid, m, n, col + 1, option, dp));
            }
        }

        return dp[col][val] = ans;
    }
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int result = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(n + 1, vector<int>(11, -1));

        for (int option = 0; option <= 9; option ++) {
            result = min(result, solve(grid, m, n, 0, option, dp));
        }
        return result;
    }
};