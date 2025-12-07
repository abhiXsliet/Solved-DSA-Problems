// https://www.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int distinctSubseq(string &s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1);
        dp[0] = 1;  // empty subsequence

        vector<int> last(256, -1);

        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            char c = s[i - 1];

            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c]] + MOD) % MOD;
            }

            last[c] = i - 1;
        }

        return dp[n];    // includes empty subsequence
    }
};