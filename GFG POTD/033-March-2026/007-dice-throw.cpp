// https://www.geeksforgeeks.org/problems/dice-throw5349/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;
    
    ll solve(int m, int n, int x, vector<vector<ll>> &dp) {
        if (n == 0) return x == 0;
        if (x <= 0) return n == 0;
        
        if (dp[n][x] != -1) return dp[n][x];
        
        ll ans = 0;
        for (int i = 1; i <= m; i ++) {
            ans += solve(m, n - 1, x - i, dp);
        }
        return dp[n][x] = ans;
    }
  public:
    int noOfWays(int m, int n, int x) {
        vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -1));
        return solve(m, n, x, dp);
    }
};