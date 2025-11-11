// https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1/




#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    // TC = O(n * m)
    // SC = O(n * m)
    int solveRec_Mem(int n, int m, string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        //base case
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
            return dp[i][j] =  1 + solveRec_Mem(n, m, s1, s2, i+1, j+1, dp);
        } else {
            return dp[i][j] = max( solveRec_Mem(n, m, s1, s2, i, j+1, dp),
                                   solveRec_Mem(n, m, s1, s2, i+1, j, dp) );
        }
    }
    
    // TC = O(n * m)
    // SC = O(n * m)
    int solveTab(int n, int m, string& s1, string& s2) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] =  1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max( dp[i][j+1], dp[i+1][j] );
                }
            }
        }
        return dp[0][0];
    }
    
    // TC = O(n * m)
    // SC = O(m)
    int solveSO(int n, int m, string& s1, string& s2) {
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    curr[j] =  1 + next[j+1];
                } else {
                    curr[j] = max( curr[j+1], next[j] );
                }
            }
            next = curr;
        }
        return next[0];
    }
    
    public:
    //Function to find length of shortest common supersequence of two strings.
    int minSuperSeq(string s1, string s2)
    {
        int m = s1.length(), n = s2.length();
        
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return ( (m + n) - solveRec_Mem(n, m, s2, s1, 0, 0, dp) );
        
        // return ( (m + n) - solveTab(n, m, s2, s1) );
        
        return ( (m + n) - solveSO(n, m, s2, s1) );
    }
};