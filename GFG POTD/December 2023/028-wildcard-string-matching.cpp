// https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    private:
    int t[1001][1001];
    // TC : O(2^(N+M))
    // SC : O(N+M) -> Recursive Depth
    bool solve_rec(string& s, string& p, int i, int j) {
        // both string consumed
        if (i == s.length() && j == p.length())
            return true;
        
        // string 's' remaining and pattern 'p' consumed
        if (i < s.length() &&  j == p.length())
            return false;
        
        // string 's' consumed and pattern 'p' remaining
        if (i == s.length()&& j < p.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') 
                    return false;
            }
            return true;
        }
        
        // match case
        if (s[i] == p[j] || p[j] == '?') {
            return solve_rec(s, p, i + 1, j + 1);
        }
        // match case
        else if (p[j] == '*') {
            return ( solve_rec(s, p, i + 1, j) || solve_rec(s, p, i, j + 1) );
        }
        // does not match case
        else return false;
    }
    
    // TC : O(N*M)
    // SC : O(N*M)
    bool solve_mem(string& s, string& p, int i, int j) {
        // both string consumed
        if (i == s.length() && j == p.length())
            return true;
        
        // string 's' remaining and pattern 'p' consumed
        if (i < s.length() &&  j == p.length())
            return false;
        
        // string 's' consumed and pattern 'p' remaining
        if (i == s.length()&& j < p.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') 
                    return false;
            }
            return true;
        }
        
        if (t[i][j] != -1)
            return t[i][j];
        
        // match case
        if (s[i] == p[j] || p[j] == '?') {
            return t[i][j] = solve_mem(s, p, i + 1, j + 1);
        }
        // match case
        else if (p[j] == '*') {
            return t[i][j] = ( solve_mem(s, p, i + 1, j) || solve_mem(s, p, i, j + 1) );
        }
        // does not match case
        else return t[i][j] = false;
    }
    
    // TC : O(N*M)
    // SC : O(N*M)
    bool solve_tab(string& s, string& p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        dp[m][n] = 1;
        
        // pattern p reamining
        for (int j = n - 1; j >= 0; j--) {
            bool flag = true;
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[m][j] = flag;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // match case
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                // match case
                else if (p[j] == '*') {
                    dp[i][j] = ( dp[i + 1][j] || dp[i][j + 1] );
                }
                // does not match case
                else dp[i][j] = 0;
            }
        }
        return dp[0][0];
    }
    
    // TC : O(N*M)
    // SC : O(M)
    bool solve_so(string& s, string& p) {
        int m = s.length();
        int n = p.length();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        next[n] = 1;
        
        // pattern p reamining
        for (int j = n - 1; j >= 0; j--) {
            bool flag = true;
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            next[j] = flag;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // match case
                if (s[i] == p[j] || p[j] == '?') {
                    curr[j] = next[j + 1];
                }
                // match case
                else if (p[j] == '*') {
                    curr[j] = ( next[j] || curr[j + 1] );
                }
                // does not match case
                else curr[j] = 0;
            }
            next = curr;
        }
        return curr[0];
    }
    public:
    bool match(string wild, string pattern)
    {
        // return solve_rec(pattern, wild, 0, 0);
        
        // memset(t, -1, sizeof(t));
        // return solve_mem(pattern, wild, 0, 0);
        
        // return solve_tab(pattern, wild);
        
        return solve_so(pattern, wild);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends