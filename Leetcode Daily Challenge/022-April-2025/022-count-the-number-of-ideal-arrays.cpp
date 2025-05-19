// https://leetcode.com/problems/count-the-number-of-ideal-arrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    const int M = 1e9 + 7;
    vector<ll> factorial;
    ll dp[10001][15];
    vector<int> countSets;

    void findSets(int m) {
        if (dp[m][1] != 0) return;    // if dp of len = 1 is already calculated then return

        dp[m][1] = 1;
        countSets[1] += 1;

        for (int div = 2; div <= m; div ++) {
            if (m % div == 0) {
                findSets(m/div);

                for (int len = 1; len < 15; len ++) {
                    if (dp[m/div][len] != 0) {
                        dp[m][len + 1]     += dp[m/div][len];
                        countSets[len + 1] += dp[m/div][len];
                    }
                }
            }
        }
    }

    ll binaryExpo(ll a, ll b) {
        if (b == 0) return 1;
        ll half = binaryExpo(a, b/2);
        ll res  = (half * half) % M;
        if (b % 2) {
            res = (res * a) % M;
        }
        return res;
    }

    ll modularNCR(int n, int r) {
        if (r < 0 || r > n) return 0;

        ll a = factorial[n];
        ll b = factorial[r] * factorial[n - r] % M;

        return a * binaryExpo(b, M - 2) % M;
    }

    ll solve(int n, int maxVal, int start, int count, vector<vector<ll>> &dp) {
        if (count == n) {
            return 1;
        }

        if (dp[start][count] != -1)
            return dp[start][count];

        ll ans = 0;
        for (int i = 1; i <= maxVal; i ++) {
            if (start * i <= maxVal) {
                ans = (ans % M + solve(n, maxVal, start * i, count + 1, dp) % M) % M;
            }
        }
        return dp[start][count] = ans;
    }

    // TC : O(maxValue * n)
    // SC : O(maxValue * n)
    int approach_1(int n, int maxValue) {
        ll ans = 0;
        vector<vector<ll>> dp(maxValue + 1, vector<ll>(n + 1, -1));
        for (int num = 1; num <= maxValue; num ++) {
            ans = (ans % M + solve(n, maxValue, num, 1, dp) % M) % M;
        }
        return (int)ans;
    }

    // TC : O(maxValue * log(maxValue))
    // SC : O(maxValue)
    int approach_2(int n, int maxValue) {
        factorial.resize(n + 1, 1);
        for (int i = 2; i <= n; i ++) {
            factorial[i] = (factorial[i - 1] * i) % M;
        }

        countSets.resize(15, 0);
        memset(dp, 0, sizeof(dp));

        // find all the sets of different len and populate the countSets
        for (int val = 1; val <= maxValue; val ++) {
            findSets(val);
        } 

        ll result = 0;
        // calculate result after getting countSets populated of different length
        for (int len = 1; len < 15; len ++) {
            if (!countSets[len]) continue;
            ll possiblity = modularNCR(n - 1, len - 1);
            result = (result + (possiblity % M * countSets[len])) % M;
        }
        return (int)result;
    }
public:
    int idealArrays(int n, int maxValue) {
        // return approach_1(n, maxValue); // TLE
        return approach_2(n, maxValue);
    }
};