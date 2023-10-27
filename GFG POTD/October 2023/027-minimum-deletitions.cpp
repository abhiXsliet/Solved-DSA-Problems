// https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1

// Longest Palindromic Subsequence variation


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  private:
    // TC = O(2^N) -> (N+M == 2N) since M == N
    // SC = O(N) -> recursive depth
    int solve_rec(string& s1, string& s2, int i, int j, int m, int n) {
        if (i >= m || j >= n) return 0;
        
        int ans = INT_MIN;
        if (s1[i] == s2[j]) {
            ans = 1 + solve_rec(s1, s2, i+1, j+1, m, n);
        }
        else {
            ans = max(solve_rec(s1, s2, i+1, j, m, n), solve_rec(s1, s2, i, j+1, m, n));
        }
        
        return ans;
    }
    
    // TC = O(N*N) since N==M
    // SC = O(N*N)
    int solve_mem(string& s1, string& s2, int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i >= m || j >= n) 
            return 0;
        
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        int ans = INT_MIN;
        if (s1[i] == s2[j]) {
            ans = 1 + solve_mem(s1, s2, i+1, j+1, m, n, dp);
        }
        else {
            ans = max(solve_mem(s1, s2, i+1, j, m, n, dp), solve_mem(s1, s2, i, j+1, m, n, dp));
        }
        
        return dp[i][j] = ans;
    }
    
    // TC = O(N*N) since N==M
    // SC = O(N*N)
    int solve_tab(string& s1, string& s2, int m, int n) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = INT_MIN;
                if (s1[i] == s2[j]) {
                    ans = 1 + dp[i+1][j+1];
                }
                else {
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }
    
    // TC = O(N*N) since N==M
    // SC = O(M)
    int solve_so(string& s1, string& s2, int m, int n) {
        vector<int> curr(m+1, 0);
        vector<int> prev(m+1, 0);
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = INT_MIN;
                if (s1[i] == s2[j]) {
                    ans = 1 + prev[j+1];
                }
                else {
                    ans = max(prev[j], curr[j+1]);
                }
                
                curr[j] = ans;
            }
            prev = curr;
        }
        
        return curr[0];
    }
    
    int solve_recursive(string S) {
        string rStr = string(rbegin(S), rend(S));
        
        int n = S.length();
        int m = rStr.length();
        
        return (m - solve_rec(S, rStr, 0, 0, m, n));
    }
    
    int solve_memoization(string S) {
        string rStr = string(rbegin(S), rend(S));
        
        int n = S.length();
        int m = rStr.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return (m - solve_mem(S, rStr, 0, 0, m, n, dp));
    }
    
    int solve_tabulation(string S) {
        string rStr = string(rbegin(S), rend(S));
        
        int n = S.length();
        int m = rStr.length();
        
        return (m - solve_tab(S, rStr, m, n));
    }
    
    int solve_space_optimization(string S) {
        string rStr = string(rbegin(S), rend(S));
        
        int n = S.length();
        int m = rStr.length();
        
        return (m - solve_so(S, rStr, m, n));
    }
  public:
    int minimumNumberOfDeletions(string S) { 
        // return solve_recursive(S);
        
        // return solve_memoization(S);
        
        // return solve_tabulation(S);
        
        return solve_space_optimization(S);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends