// https://leetcode.com/problems/distribute-candies-among-children-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    ll dp[1000001][4];

    ll solve(int n, int limit, int child) {
        if (child == 3) {
            return (n == 0) ? 1 : 0;
        }

        if (dp[n][child] != -1) return dp[n][child];

        ll  ways = 0;
        for (int i = 0; i <= min(limit, n); i ++) {
            ways += solve(n - i, limit, child + 1);
        }
        return dp[n][child] = ways;
    }

    // TC : O(N*limit)
    // SC : O(N)
    ll approach_1(int n, int limit) {
        memset(dp, -1, sizeof(dp));
        return solve(n, limit, 0);
    }

    // TC : O(N)
    // SC : O(1)
    ll approach_2(int n, int limit) {
        int minCh1 = max(0, n - 2*limit);   // assign => ch2 = limit, ch3 = limit
        int maxCh1 = min(n, limit);

        ll ways = 0;
        for (int i = minCh1; i <= maxCh1; i ++) {
            
            int N = (n - i);    // remaining candies for ch2 and ch3

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += (maxCh2 - minCh2 + 1);

        }
        return ways;
    }
    long long distributeCandies(int n, int limit) {
        // return approach_1(n, limit);
        return approach_2(n, limit);
    }
};