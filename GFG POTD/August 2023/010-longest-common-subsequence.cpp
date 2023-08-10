// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1



//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
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
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {   
        // Memoization
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solveRec_Mem(n, m, s1, s2, 0, 0, dp);
        
        // // Tabulation
        // return solveTab(n, m, s1, s2);
        
        // Space Optimization
        return solveSO(n, m, s1, s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends