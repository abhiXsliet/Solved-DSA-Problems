// https://leetcode.com/problems/coin-change-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(2^n)
    // SC = O(n) -> due to recursive call stack
    int solveRec(int amount, vector<int>& coins, int i) {
        // base case
        if (amount == 0) return 1;
        if (i == coins.size()) return 0;

        int include = 0;
        if(amount >= coins[i]) {
            include = solveRec(amount - coins[i], coins, i);
        }
        int exclude = solveRec(amount, coins, i+1);

        return (include + exclude);
    }

    // TC = O(n * amount)
    // SC = O(n * amount)
    int solveMem(int amount, vector<int>& coins, int i, vector<vector<int>>& dp) {
        // base case
        if (amount == 0) return 1;
        if (i == coins.size()) return 0;

        if (dp[amount][i] != -1) return dp[amount][i];

        int include = 0;
        if(amount >= coins[i]) {
            include = solveMem(amount - coins[i], coins, i, dp);
        }
        int exclude = solveMem(amount, coins, i+1, dp);

        return dp[amount][i] = (include + exclude);
    }

    // TC = O(n * amount)
    // SC = O(n * amount)
    int solveTab(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1, 0));

        // After analyzing base case
        for(int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= amount; j++) {
                int include = 0;
                if(j >= coins[i]) {
                    include = dp[j - coins[i]][i];
                }
                int exclude = dp[j][i+1];

                dp[j][i] = (include + exclude);
            }
        }
        return dp[amount][0];
    }

    // TC = O(n * amount)
    // SC = O(amount)
    int solveSO(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> curr(amount+1, 0);
        vector<int> next(amount+1, 0);

        // After analyzing base case
        curr[0] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= amount; j++) {
                int include = 0;
                if(j >= coins[i]) {
                    include = curr[j - coins[i]];
                }
                int exclude = next[j];

                curr[j] = (include + exclude);
            }
            next = curr;
        }
        return curr[amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        // // Recursion
        // return solveRec(amount, coins, 0);


        // // Recursion + Memoization
        // int n = coins.size();
        // vector<vector<int>> dp(amount+1, vector<int>(n+1, -1));
        // return solveMem(amount, coins, 0, dp);


        // // Tabulation
        // return solveTab(amount, coins);


        // Space-Optimized
        return solveSO(coins, amount);
    }
};