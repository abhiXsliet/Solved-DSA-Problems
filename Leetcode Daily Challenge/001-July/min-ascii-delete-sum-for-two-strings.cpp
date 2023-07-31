// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solveRec(string& s1, string& s2, int i, int j) {
        int m = s1.length();
        int n = s2.length();

        if(i >= m && j >= n) 
            return 0;

        if(j >= n) // string s2 over
            return s1[i] + solveRec(s1, s2, i+1, j);

        if(i >= m) // string s1 over
            return s2[j] + solveRec(s1, s2, i, j+1);
        
        if(s1[i] == s2[j]) 
            return solveRec(s1, s2, i+1, j+1);

        // Two Options
        int delete_i = s1[i] + solveRec(s1, s2, i+1, j);
        int delete_j = s2[j] + solveRec(s1, s2, i, j+1);

        return min(delete_i, delete_j);
    }

    int solveRec_Mem(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        int m = s1.length();
        int n = s2.length();

        if(i >= m && j >= n) 
            return 0;

        if(j >= n) // string s2 over
            return s1[i] + solveRec_Mem(s1, s2, i+1, j, dp);

        if(i >= m) // string s1 over
            return s2[j] + solveRec_Mem(s1, s2, i, j+1, dp);
        
        if(s1[i] == s2[j]) 
            return solveRec_Mem(s1, s2, i+1, j+1, dp);

        if(dp[i][j] != -1) 
            return dp[i][j];

        // Two Options
        int delete_i = s1[i] + solveRec_Mem(s1, s2, i+1, j, dp);
        int delete_j = s2[j] + solveRec_Mem(s1, s2, i, j+1, dp);

        return dp[i][j] = min(delete_i, delete_j);
    }

    int solveTab(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // Analyze base cases
        for(int i = m-1; i >= 0; i--) { // string s2 over
            dp[i][n] = s1[i] + dp[i+1][n];
        }

        for(int j = n-1; j >= 0; j--) { // string s1 over
            dp[m][j] = s2[j] + dp[m][j+1];
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >=0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];

                } else {
                    int delete_i = s1[i] + dp[i+1][j];
                    int delete_j = s2[j] + dp[i][j+1];
                    dp[i][j] = min(delete_i, delete_j);
                }
            }
        }
        return dp[0][0];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        // // Recursion -> TLE
        // return solveRec(s1, s2, 0, 0);


        // // Recursion + Memoization
        // int m = s1.length();
        // int n = s2.length();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveRec_Mem(s1, s2, 0, 0, dp);


        // // Tabulation
        return solveTab(s1, s2);
    }
};