// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> dp;
    int totalAsciiSum = 0;

    int solve(string s1, string s2, int i, int j) {
        if (i >= n || j >= m)
            return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int op1 = 0, op2 = 0, op3 = 0;
        if (s1[i] == s2[j]) {
            op1 = (int)s1[i] + solve(s1, s2, i + 1, j + 1);
        } else {
            op2 = solve(s1, s2, i + 1, j);
            op3 = solve(s1, s2, i, j + 1);
        }

        return dp[i][j] = max({op1, op2, op3});
    }

    // TC : O(N*M)
    // SC : O(N*M)
    int approach_1(string s1, string s2) {
        dp.assign(n + 1, vector<int>(m + 1, -1));

        int maxSubSeqSum = solve(s1, s2, 0, 0);
        return totalAsciiSum - 2*maxSubSeqSum;
    }

    // TC : O(N*M)
    // SC : O(N*M)
    int approach_2(string s1, string s2) {
        dp.assign(n + 1, vector<int>(m + 1, 0));

        // for (int j = 0; j < m; j ++) dp[n][j] = 0;
        // for (int i = 0; i < n; i ++) dp[i][m] = 0;

        for (int i = n - 1; i >= 0; i --) {
            for (int j = m - 1; j >= 0; j --) {
                
                int op1 = 0, op2 = 0, op3 = 0;
                if (s1[i] == s2[j]) {
                    op1 = (int)s1[i] + dp[i + 1][j + 1];
                } else {
                    op2 = dp[i + 1][j];
                    op3 = dp[i][j + 1];
                }
                
                dp[i][j] = max({op1, op2, op3});
            }
        }

        int maxSubSeqSum = dp[0][0];
        return totalAsciiSum - 2*maxSubSeqSum;
    }

    // TC : O(N*M)
    // SC : O(M)
    int approach_3(string s1, string s2) {
        vector<int> curr(m + 1, 0), prev(m + 1, 0);

        for (int i = n - 1; i >= 0; i --) {
            for (int j = m - 1; j >= 0; j --) {
                
                int op1 = 0, op2 = 0, op3 = 0;
                if (s1[i] == s2[j]) {
                    op1 = (int)s1[i] + prev[j + 1];
                } else {
                    op2 = prev[j];
                    op3 = curr[j + 1];
                }
                
                curr[j] = max({op1, op2, op3});
            }
            prev = curr;
        }

        int maxSubSeqSum = curr[0];
        return totalAsciiSum - 2*maxSubSeqSum;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        n = s1.length();
        m = s2.length();

        for (char &ch : s1) totalAsciiSum += (int)ch;
        for (char &ch : s2) totalAsciiSum += (int)ch;

        // return approach_1(s1, s2);  // mle
        // return approach_2(s1, s2);
        return approach_3(s1, s2);
    }
};