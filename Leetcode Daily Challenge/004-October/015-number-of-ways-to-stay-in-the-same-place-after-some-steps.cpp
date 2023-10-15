// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/


#include <bits/stdc++.h>
using namespace std;


class Solution {
    int n;
    int dp[501][501];
    int MOD = 1e9 + 7;
    int solve_mem(int idx, int steps) {
        if (idx < 0 || idx >= n) 
            return 0;

        if (steps == 0) 
            return idx == 0;

        if (dp[idx][steps] != -1)
            return dp[idx][steps];

        int result = solve_mem(idx + 1, steps - 1);     // RIGHT

        result = (result + solve_mem(idx - 1, steps - 1)) % MOD; // LEFT

        result = (result + solve_mem(idx, steps -1)) % MOD;  // STAY

        return dp[idx][steps] = result;
    }
public:
    int numWays(int steps, int arrLen) {
        // arrLen = min(steps, arrLen);
        
        arrLen = min(steps/2 + 1, arrLen); // slightly more optimization

        n = arrLen;
        memset(dp, -1, sizeof(dp));

        return solve_mem(0, steps);
    }
};