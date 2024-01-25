// https://leetcode.com/problems/longest-common-subsequence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC : O(2^(n+m))
    // SC : O(n+m) -> recursive call stack
    int solveRec(string& text1, string& text2, int n, int m, int i, int j) {
        if(i >= n || j >= m)
            return 0;
        
        if(text1[i] == text2[j]) 
            return 1+solveRec(text1, text2, n, m, i+1, j+1);
        else 
            return max(solveRec(text1, text2, n, m, i, j+1), solveRec(text1, text2, n, m, i+1, j));
    }

    // TC : O(n*m)
    // SC : O(n*m)
    int solveMem(string& text1, string& text2, int n, int m, int i, int j, vector<vector<int>>& dp) {
        if(i >= n || j >= m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j]) 
            return 1+solveMem(text1, text2, n, m, i+1, j+1, dp);
        else 
            return dp[i][j] = max(solveMem(text1, text2, n, m, i, j+1, dp), solveMem(text1, text2, n, m, i+1, j, dp));
    }

    // TC : O(n*m)
    // SC : O(n*m)
    int solveTab(string& text1, string& text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) 
                    ans = 1+dp[i+1][j+1];
                else 
                    ans = max(dp[i][j+1], dp[i+1][j]);
                
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    // TC : O(n*m)
    // SC : O(m)
    int solveSO(string& text1, string& text2) {
        int n = text1.length();
        int m = text2.length();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) 
                    ans = 1+next[j+1];
                else 
                    ans = max(curr[j+1], next[j]);
                
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        // return solveRec(text1, text2, n, m, 0, 0);

        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // return solveMem(text1, text2, n, m, 0, 0, dp);

        // return solveTab(text1, text2);

        return solveSO(text1, text2);
    }
};