// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n;
    int dp[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && neu > 0) {
                return 0;   // neutralized the robber
            }
            return coins[i][j];
        }

        if (i >= m || j >= n) return INT_MIN;

        if (dp[i][j][neu] != INT_MIN) return dp[i][j][neu];


        int take = coins[i][j] + max(solve(coins, i + 1, j, neu), solve(coins, i, j + 1, neu));

        int skip = INT_MIN;
        if (coins[i][j] < 0 && neu > 0) {
            int skipRight = solve(coins, i, j + 1, neu - 1);
            int skipDown  = solve(coins, i + 1, j, neu - 1);
            skip = max(skipRight, skipDown);
        }

        return dp[i][j][neu] = max(take, skip);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size(), n = coins[0].size();
        for (int i = 0; i <= 500; i ++) {
            for (int j = 0; j <= 500; j ++) {
                for (int k = 0; k <= 2; k ++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins, 0, 0, 2);
    }
};