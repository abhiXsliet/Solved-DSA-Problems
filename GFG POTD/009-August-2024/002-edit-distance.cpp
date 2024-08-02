// https://www.geeksforgeeks.org/problems/edit-distance3702/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int dp[101][101];
    
    // TC = O(N*M)
    // SC = O(N*M)
    int solve_mem(string& s, string& t, int i, int j) {
        if (i == s.length()) return (t.length() - j);
        if (j == t.length()) return (s.length() - i);
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        
        if (s[i] == t[j]) {
            ans = solve_mem(s, t, i+1, j+1);
        }
        else {
            int insert  = 1 + solve_mem(s, t, i, j+1);
            int remove  = 1 + solve_mem(s, t, i+1, j);
            int replace = 1 + solve_mem(s, t, i+1, j+1);
            
            ans = min(insert, min(remove, replace));
        }
        return dp[i][j] = ans;
    }

    // TC = O(N*M)
    // SC = O(N*M)
    int solve_tab(string& s, string& t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int j = 0; j < m; j++) {
            dp[n][j] = m - j;
        }
        
        for (int i = 0; i < n; i++) {
            dp[i][m] = n - i;
        }
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                int ans = 0;
                
                if (s[i] == t[j]) 
                    ans = dp[i+1][j+1];
                else {
                    int insert  = 1 + dp[i][j+1];
                    int remove  = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    
                    ans = min(insert, min(remove, replace));
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }
    
    // TC = O(N*M)
    // SC = O(M)
    int solve_so(string& s, string& t) {
        int n = s.length();
        int m = t.length();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for (int j = 0; j < m; j++) {
            next[j] = m - j;
        }
        
        for (int i = n-1; i >= 0; i--) {
            // catch
            curr[m] = n - i;
            
            for (int j = m-1; j >= 0; j--) {
                int ans = 0;
                
                if (s[i] == t[j]) 
                    ans = next[j+1];
                else {
                    int insert  = 1 + curr[j+1];
                    int remove  = 1 + next[j];
                    int replace = 1 + next[j+1];
                    
                    ans = min(insert, min(remove, replace));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        
        return curr[0];
    }
  public:
    int editDistance(string s, string t) {
        // memset(dp, -1, sizeof(dp));
        // return solve_mem(s, t, 0, 0);
        
        // return solve_tab(s, t);
        
        return solve_so(s, t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends