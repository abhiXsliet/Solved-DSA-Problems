// https://www.geeksforgeeks.org/problems/valid-number-of-parenthesis/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count = 0;
    void solve(int open, int close, int maxPairs) {
        if (open == maxPairs && close == maxPairs) {
            count++;
            return;
        }

        if (open < maxPairs) {
            solve(open + 1, close, maxPairs);
        }

        if (close < open) {
            solve(open, close + 1, maxPairs);
        }
    }
    
    int approach_1(int n) {
        if (n % 2 == 1) return 0;
        solve(0, 0, n / 2);
        return count;
    }
    
    int approach_2(int n) {
        if (n % 2 == 1) return 0;

        int k = n / 2;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[k];
    }
  public:
    int findWays(int n) {
        // return approach_1(n);
        return approach_2(n);
    }
};