// https://www.geeksforgeeks.org/problems/interleaved-strings/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        dp[0][0] = 1;

        // fill first row
        for (int i = 1; i <= n1; i++) {
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = dp[i - 1][0];
        }

        // fill first column
        for (int j = 1; j <= n2; j++) {
            if (s2[j - 1] == s3[j - 1])
                dp[0][j] = dp[0][j - 1];
        }

        // fill rest
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                char c = s3[i + j - 1];
                if (s1[i - 1] == c)
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (s2[j - 1] == c)
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }

        return dp[n1][n2];
    }
};