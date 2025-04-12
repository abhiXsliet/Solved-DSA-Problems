// https://leetcode.com/problems/longest-ideal-subsequence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    int solve(string &s, int k, int prev, int curr, vector<vector<int>> &dp) {
        if (curr >= n) return 0;
        
        if (dp[prev + 1][curr] != -1)
            return dp[prev + 1][curr];

        int ans = solve(s, k, prev, curr + 1, dp);

        if ((prev == -1) || (abs(s[curr] - s[prev]) <= k)) {
            ans = max(ans, 1 + solve(s, k, curr, curr + 1, dp));
        }
        
        return dp[prev + 1][curr] = ans;
    }

    // TC : O(N * N)
    // SC : O(N * N)
    int top_down(string &s, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(s, k, -1, 0, dp);
    }

    // TC : O(N * N)
    // SC : O(N)
    int bottom_up(string &s, int k) {
        vector<int> dp(n, 1);
        int maxLen = 0;
        for (int curr = 1; curr < n; curr ++) {
            for (int prev = 0; prev < curr; prev ++) {
                if (abs(s[curr] - s[prev]) <= k) {
                    dp[curr] = max(dp[curr], dp[prev] + 1);
                    maxLen = max(maxLen, dp[curr]);
                }
            }
        }
        return maxLen;
    }

    // TC : O(N)
    // SC : O(N)
    int optimal(string &s, int k) {
        vector<int> freq(26, 0);
        vector<int> dp(n, 1);

        int maxLen = 0;
        for (int curr = 0; curr < n; curr ++) {
            for (int prev = 0; prev < 26; prev ++) {
                if (abs(s[curr] - (prev + 'a')) <= k) {
                    dp[curr] = max(dp[curr], freq[prev] + 1);
                }
            }
            freq[s[curr] - 'a'] = dp[curr];
            maxLen = max(maxLen, dp[curr]);
        }
        return maxLen;
    }

    // TC : O(N)
    // SC : O(1)
    int optimalFast(string &s, int k) {
        vector<int> freq(26, 0);
        int maxLen = 0;
        for (int curr = 0; curr < n; curr ++) {
            int currSeqLen = 1;
            for (int prev = 0; prev < 26; prev ++) {
                if (abs(s[curr] - (prev + 'a')) <= k) {
                    currSeqLen = max(currSeqLen, freq[prev] + 1);
                }
            }
            freq[s[curr] - 'a'] = currSeqLen;
            maxLen = max(maxLen, currSeqLen);
        }
        return maxLen;
    }
public:
    int longestIdealString(string s, int k) {
        n = s.length();

        // return top_down(s, k);
        // return bottom_up(s, k);
        // return optimal(s, k);
        return optimalFast(s, k);
    }
};