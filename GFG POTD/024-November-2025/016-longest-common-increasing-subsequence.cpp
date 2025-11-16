// https://www.geeksforgeeks.org/problems/longest-common-increasing-subsequence1437/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N * M)
    // SC : O(M)
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();

        vector<int> dp(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int best = 0;

            for (int j = 0; j < m; j++) {

                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], best + 1);
                    ans = max(ans, dp[j]);
                }

                if (b[j] < a[i]) {
                    best = max(best, dp[j]);
                }
            }
        }

        return ans;
    }
};