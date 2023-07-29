// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1



//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    //TC => O(2^N) where N is the length of the string
    //SC => O(N) -> Recursive call stack
    int solveRec(string& A, string& B, int i, int j) {
        //base case
        if(i == A.length()) return 0;
        if(j == B.length()) return 0;
        
        int ans = INT_MIN;
        if(A[i] == B[j]) {
            ans = 1 + solveRec(A, B, i+1, j+1);
        } else {
            ans = max(solveRec(A, B, i, j+1), solveRec(A, B, i+1, j));
        }
        return ans;
    }
    
    //TC => O(N^2)
    //SC => O(N^2)
    int solveMem(string& A, string& B, int i, int j, vector<vector<int>>& dp) {
        //base case
        if(i == A.length()) return 0;
        if(j == B.length()) return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MIN;
        if(A[i] == B[j]) {
            ans = 1 + solveMem(A, B, i+1, j+1, dp);
        } else {
            ans = max(solveMem(A, B, i, j+1, dp), solveMem(A, B, i+1, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    //TC => O(N^2)
    //SC => O(N^2)    
    int solveTab(string& A, string& B) {
        int n = A.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int ans = INT_MIN;
                if(A[i] == B[j]) {
                    ans = 1 + dp[i+1][j+1];
                } else {
                    ans = max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    
    //TC => O(N^2)
    //SC => O(N)    
    int solveSO(string& A, string& B) {
        int n = A.length();
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int ans = INT_MIN;
                if(A[i] == B[j]) {
                    ans = 1 + next[j+1];
                } else {
                    ans = max(curr[j+1], next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
  public:
    int longestPalinSubseq(string A) {
        string B = A;
        reverse(B.begin(), B.end());
        
        //Recursive Solution -> TLE
        // return solveRec(A, B, 0, 0);
        
        //Recursion + Memoization 
        // int n = A.length();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(A, B, 0, 0, dp);
        
        
        //Tabulation
        // return solveTab(A, B);
            
        //Space-Optimization
        return solveSO(A, B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends