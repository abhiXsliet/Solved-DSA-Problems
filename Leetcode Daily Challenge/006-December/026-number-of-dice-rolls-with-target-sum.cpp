// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    int t[31][1001];

    // T.C : O(n*target*k) (But without memoization - it will be O(k^n)
    // S.C : O(31*1001) ~= O(1)
    int solve_mem(int n, int k, int target) {
        if (target < 0) 
            return 0;
        
        if (n == 0)  // check if target meet or not
            return target == 0;

        if (t[n][target] != -1)
            return t[n][target];

        int ways = 0;

        for (int face = 1; face <= k; face++) { // one dice rolled
            ways = (ways + solve_mem(n - 1, k, target - face)) % MOD;
        }

        return t[n][target] = ways;
    }

    // T.C : O(n*target*k)
    // S.C : O(n*target)
    int solve_tab(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        // dp[i][j] -> no. of ways to obtain sum = j, if we have 'i' dices
        
        dp[0][0] = 1; // n == 0 && target == 0 

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // i = no. of dices
                // j = target value

                int ways = 0;
                for (int face = 1; face <= k; face++) {
                    if (j >= face) {
                        ways = (ways + dp[i - 1][j - face]) % MOD;
                    }
                }
                dp[i][j] = ways;
            }
        }

        return dp[n][target];
    }

    // TC : O(n * k * target)
    // SC : O(target)
    int solve_so(int n, int k, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> new_dp(target+1, 0);
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k; face++) {
                    if (j >= face) {
                        new_dp[j] = (new_dp[j] + dp[j - face]) % MOD;
                    }
                }
            }
            dp = new_dp;
        }

        return dp[target];
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        // memset(t, -1, sizeof(t));
        // return solve_mem(n, k, target);

        // return solve_tab(n, k, target);

        return solve_so(n, k, target);
    }
};