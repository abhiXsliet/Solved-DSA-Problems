// https://www.geeksforgeeks.org/problems/distinct-occurrences/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    private:
    int dp[1001][1001];
    int M = 1e9 + 7;
    
    // TC : O(N*M) Where N = s.length() & M = t.length()
    // SC : O(N*M) 
    int mem(string& s, string& t, int i, int j) {
        if (j < 0) return 1;
        if (i < 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j]) {
            return dp[i][j] = (mem(s, t, i - 1, j - 1) % M + mem(s, t, i - 1, j) % M) % M;
        }
        return dp[i][j] = mem(s, t, i - 1, j) % M;
    }
    
    // TC : O(N*M) Where N = s.length() & M = t.length()
    // SC : O(N*M) 
    int tab(string& s, string& t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // If t is empty, we have found a subsequence
        for (int i = 0; i <= m; i++) 
            dp[i][0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] % M + dp[i - 1][j] % M) % M;
                }
                else dp[i][j] = dp[i - 1][j] % M;
            }
        }
        
        return dp[m][n];
    }
    
    // TC : O(N*M) Where N = s.length() & M = t.length()
    // SC : O(M) 
    int so(string& s, string& t) {
        int m = s.length();
        int n = t.length();
        vector<int> curr(n + 1, 0);
        vector<int> prev(n + 1, 0);
        
        prev[0] = curr[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = (prev[j - 1] % M + prev[j] % M) % M;
                }
                else curr[j] = prev[j] % M;
            }
            prev = curr;
        }
        
        return curr[n];
    }
    
    // TC : O(N*M) Where N = s.length() & M = t.length()
    // SC : O(1) 
    int optimal(string& s, string& t) {
        int m = s.length();
        int n = t.length();
        
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = (dp[j - 1] % M + dp[j] % M) % M;
                }
            }
        }
        
        return dp[n];
    }
    public:
    int subsequenceCount(string s, string t)
    {
        // memset(dp, -1, sizeof(dp));
        // return mem(s, t, s.length() - 1, t.length() - 1);
        
        // return tab(s, t);
        
        // return so(s, t);
        
        return optimal(s, t);
    }
};


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends