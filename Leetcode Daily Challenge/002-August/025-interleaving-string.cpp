// https://leetcode.com/problems/interleaving-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC = O(2^N) where N = s3.length()
    // SC = O(N) -> Due to recursive call stack
    bool solve_Rec(string& s1, string& s2, string& s3, int i, int j, int k) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();

        // base case
        if (i >= m && j >= n && k >= N) return 1;
        if (k >= N) return 0;

        bool result = 0;
        if (s1[i] == s3[k])
            result = solve_Rec(s1, s2, s3, i+1, j, k+1);

        if (result) return result;

        if (s2[j] == s3[k])
            result = solve_Rec(s1, s2, s3, i, j+1, k+1);
        
        return result;
    }

    // TC = O(m*n*N)
    // SC = O(m*n*N)
    bool solve_Mem(string& s1, string& s2, string& s3, 
                    int i, int j, int k, vector<vector<vector<int>>>& dp) {
        
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();

        // base case
        if (i == m && j == n && k == N) return 1;
        if (k >= N) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool result = 0;
        if (s1[i] == s3[k])
            result = solve_Mem(s1, s2, s3, i+1, j, k+1, dp);

        // in case if result == 1 then return 
        if (result) return dp[i][j][k] = result;

        if (s2[j] == s3[k])
            result = solve_Mem(s1, s2, s3, i, j+1, k+1, dp);
        
        return dp[i][j][k] = result;
    }

    // TC = O(n*m*N)
    // SC = O(n*m*N)
    bool solve_Tab(string& s1, string& s2, string& s3) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();

        vector<vector<vector<int>>> dp( m+1, vector<vector<int>>(n+1, 
                                                vector<int>(N+1, 0)) );

        // After Analyzing Base Case
        dp[m][n][N] = 1;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                for (int k = N-1; k >= 0; k--) {
  
                    bool result = false;
                    if (s1[i] == s3[k])
                        result = dp[i + 1][j][k + 1];

                    if (s2[j] == s3[k])
                        result = result || dp[i][j + 1][k + 1];

                    dp[i][j][k] = result;  

                }
            }
        }
        return dp[0][0][0];
    }

    // TC = O(m*n)
    // SC = O(m*n)
    bool solve_Mem_II(string& s1, string& s2, string& s3, 
                    int i, int j, vector<vector<int>>& dp) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();

        // base case
        if (i >= m && j >= n && (i+j) >= N) return 1;
        if ((i+j) >= N) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        bool result = 0;
        if (s1[i] == s3[i+j])
            result = solve_Mem_II(s1, s2, s3, i+1, j, dp);

        if (result) return result;

        if (s2[j] == s3[i+j])
            result = solve_Mem_II(s1, s2, s3, i, j+1, dp);
        
        return dp[i][j] = result;
    }

    // TC = O(m*n)
    // SC = O(m*n)
    bool solve_Tab_II(string& s1, string& s2, string& s3) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();

        if (m + n != N) {
            return false;  // Length mismatch, early return false
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m][n] = 1;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                
                if (i < m && s1[i] == s3[i + j])
                    dp[i][j] |= dp[i + 1][j];

                if (j < n && s2[j] == s3[i + j])
                    dp[i][j] |= dp[i][j + 1];
            }
        }
        return dp[0][0];
    }

public:
    bool isInterleave(string s1, string s2, string s3) {

        // // Recursive Approach -> TLE
        // return solve_Rec(s1, s2, s3, 0, 0, 0);

        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
    
        // // Recursion + Memoization
        // vector<vector<vector<int>>> dp( m+1, vector<vector<int>>(n+1, 
        //                                     vector<int>(N+1, -1)) );
        // return solve_Mem(s1, s2, s3, 0, 0, 0, dp);


        // // Tabulation
        // return solve_Tab(s1, s2, s3);

        
        // // Recursion + Memoization -> with 2-variables only
        // vector<vector<int>> dp( m+1, vector<int>(n+1, -1) );
        // return solve_Mem_II(s1, s2, s3, 0, 0, dp);

        
        // Tabulation -> with 2-variable only
        return solve_Tab_II(s1, s2, s3);
    }
};