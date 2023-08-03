// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solveRec(string& s1, string& s2, int i, int j) {
        if(i == s1.length()) return 0;
        if(j == s2.length()) return 0;

        int ans = 0;
        if(s1[i] == s2[j]) {
            ans = s1[i] + solveRec(s1, s2, i+1, j+1);
        } else {
            ans = max(solveRec(s1, s2, i+1, j), solveRec(s1, s2, i, j+1));
        }
        return ans;
    }

    int solveRec_Mem(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if(i == s1.length()) return 0;
        if(j == s2.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s1[i] == s2[j]) {
            ans = s1[i] + solveRec_Mem(s1, s2, i+1, j+1, dp);
        } else {
            ans = max(solveRec_Mem(s1, s2, i+1, j, dp), solveRec_Mem(s1, s2, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }

    int solveTab(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int ans = 0;
                if(s1[i] == s2[j]) {
                    ans = s1[i] + dp[i+1][j+1];
                } else {
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSO(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int ans = 0;
                if(s1[i] == s2[j]) {
                    ans = s1[i] + next[j+1];
                } else {
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        int sum1 = 0;
        for(int i = 0; i < m; i++) {
            sum1 += s1[i];
        }
        int sum2 = 0;
        for(int i = 0; i < n; i++) {
            sum2 += s2[i];
        }

        // // Recursion
        // return ( (sum1 + sum2) - ( 2 * solveRec(s1, s2, 0, 0) ) );

        // // Recursion + Memoization
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return ( (sum1 + sum2) - (2 * solveRec_Mem(s1, s2, 0, 0, dp)) );

        // // Tabulation
        // return sum1+sum2 - 2*solveTab(s1, s2);

        // Space - Optimization
        return sum1+sum2 - 2*solveSO(s1, s2);
    }
};