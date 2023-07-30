// https://leetcode.com/problems/strange-printer/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC = O(2^N)
    // SC = O(N) -> Recursive depth of recursion on call stack
    int solveRec(int i, int j, string& s) {
        if(i == j) return 1;

        int ans = INT_MAX;
        for(int k = i; k < j; k++) {
            ans = min(ans, solveRec(i, k, s) + solveRec(k+1, j, s));
        }
        if(s[i] == s[j])
            ans--;
        return ans;
    }

    // TC = O(N^3)
    // SC = O(N^2)
    int solveRec_Mem(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k = i; k < j; k++) {
            ans = min(ans, solveRec_Mem(i, k, s, dp) + solveRec_Mem(k+1, j, s, dp));
        }
        if(s[i] == s[j]) ans --;
        return dp[i][j] = ans;
    }

    // TC = O(N^3)
    // SC = O(N^2)
    int solveTab(string& s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++) {

                int ans = INT_MAX;
                for(int k = i; k < j; k++) {
                    ans = min(ans, dp[i][k] + dp[k+1][j]);
                }
                if(s[i] == s[j]) ans--;
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
public:
    int strangePrinter(string s) {
        int n = s.length();
        // Recursive Approach
        // return solveRec(0, n - 1, s);

        // Recursion + Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveRec_Mem(0, n - 1, s, dp);

        // Tabulation
        return solveTab(s);
    }
};