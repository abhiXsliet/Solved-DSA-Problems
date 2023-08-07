// https://leetcode.com/problems/number-of-music-playlists/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    #define ll long long
    const int mod = 1e9 + 7;
    // TC = O(2^n)
    // SC = O(n) -> space used by recursive call stack
    ll solve(int n, int goal, int k) {
        if(n == 0 && goal == 0) return 1;
        if(n == 0 || goal == 0) return 0;

        ll include = solve(n - 1, goal - 1, k) * n;
        ll exclude = solve(n, goal - 1, k) * max(n - k, 0);
        ll ans = (include + exclude) % mod;
        return ans;
    }

    // TC = O(n^2)
    // SC = O(n^2)
    ll solveMem(int n, int goal, int k, vector<vector<int>>& dp) {
        if(n == 0 && goal == 0) return 1;
        if(n == 0 || goal == 0) return 0;

        if(dp[n][goal] != -1) return dp[n][goal];

        ll include = solveMem(n - 1, goal - 1, k, dp) * n;
        ll exclude = solveMem(n, goal - 1, k, dp) * max(n - k, 0);
        ll ans = (include + exclude) % mod;

        return dp[n][goal] = ans;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        // // Recursive -> TLE
        // return solve(n, goal, k);

        // Recursion + Memoization
        vector<vector<int>> dp(n+1, vector<int>(goal+1, -1));
        return solveMem(n, goal, k, dp);
    }
};