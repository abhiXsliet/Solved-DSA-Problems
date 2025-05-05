// https://leetcode.com/problems/domino-and-tromino-tiling/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int M = 1e9 + 7;
    int dp[1001];

    int solve(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;

        if (dp[n] != -1) return dp[n];
        
        return dp[n] = ((2 * solve(n - 1)) % M + solve(n - 3) % M) % M;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(int n) {
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i ++) {
            dp[i] = ((2 * dp[i - 1]) % M + dp[i - 3] % M) % M;
        }
        return dp[n];
    }
public:
    int numTilings(int n) {
        // return approach_1(n);
        return approach_2(n);
    }
};