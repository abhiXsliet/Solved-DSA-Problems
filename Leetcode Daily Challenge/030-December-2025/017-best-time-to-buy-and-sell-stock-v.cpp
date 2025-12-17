// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<vector<long long>>> dp;
    const long long NEG = -1e18;

    long long solve(vector<int>& prices, int k, int prev, int curr) {
        if (curr == prices.size() || k == 0) {
            return (prev == -1) ? 0 : NEG;
        }

        long long &ans = dp[curr][k][prev + 1];
        if (ans != NEG) return ans;

        ans = NEG;

        // skip
        ans = max(ans, solve(prices, k, prev, curr + 1));

        if (prev == -1) {
            // buy (long)
            ans = max(ans, -prices[curr] + solve(prices, k, 0, curr + 1));
            // short sell
            ans = max(ans, prices[curr] + solve(prices, k, 1, curr + 1));
        }
        else if (prev == 0) {
            // sell (complete long transaction)
            ans = max(ans, prices[curr] + solve(prices, k - 1, -1, curr + 1));
        }
        else if (prev == 1) {
            // buy back (complete short transaction)
            ans = max(ans, -prices[curr] + solve(prices, k - 1, -1, curr + 1));
        }

        return ans;
    }

public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        dp.assign(n, vector<vector<long long>>(k + 1,
                   vector<long long>(3, NEG)));

        return solve(prices, k, -1, 0);
    }
};