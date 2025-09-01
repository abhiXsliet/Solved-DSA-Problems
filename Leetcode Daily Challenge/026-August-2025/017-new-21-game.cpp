// https://leetcode.com/problems/new-21-game/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * maxPts)
    // SC : O(N)
    double approach_1(int n, int k, int maxPts) {
        if (k == 0.0) return 1.0;
        if (n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);   // dp[i] prob. of getting point 'i'

        dp[0] = 1.0;
        for (int i = 1; i <= n; i ++) {
            for (int pt = 1; pt <= maxPts; pt ++) {
                if (i - pt >= 0 && i - pt < k) {
                    dp[i] += dp[i - pt] * (1.0 / maxPts);
                }
            }
        }
        
        double prob = 0.0;
        for (int i = k; i <= n; i ++) {
            prob += dp[i];
        }
        return prob;
    }

    // TC : O(N)
    // SC : O(N)
    double approach_2(int n, int k, int maxPts) {
        if (k == 0.0) return 1.0;
        if (n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);   // dp[i] prob. of getting point 'i'
        dp[0] = 1.0;

        double windowSum = 1.0;
        double prob      = 0.0;

        for (int i = 1; i <= n; i ++) {
            dp[i] = windowSum / maxPts;

            if (i < k) windowSum += dp[i];
            else prob += dp[i];

            if (i >= maxPts) windowSum -= dp[i - maxPts];
        }
        
        return prob;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        // return approach_1(n, k, maxPts);
        return approach_2(n, k, maxPts);
    }
};