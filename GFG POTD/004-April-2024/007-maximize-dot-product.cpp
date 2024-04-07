// https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    // TC : O(N^2 * M) ~= O(10^9) TLE
    // SC : O(N^2 * M)
    int solve_mem(int i, int j, int zeroCnt, int a[], int b[], int n, int m, vector<vector<vector<int>>>& dp) {
        if (i >= n) return 0;
        if (dp[i][j][zeroCnt] != -1) {
            return dp[i][j][zeroCnt];
        }
        int ans = INT_MIN;
        
        if (zeroCnt > 0) {
            ans = max(ans, a[i]*0 + solve_mem(i+1, j, zeroCnt-1, a, b, n, m, dp));
        }
        
        if (j < m) {
            ans = max(ans, a[i]*b[j] + solve_mem(i+1, j+1, zeroCnt, a, b, n, m, dp));
        }
        
        return dp[i][j][zeroCnt] = ans;
    }
    
    // TC : O(N * M)
    // SC : O(N * M)
    int solve_tab(int a[], int b[], int n, int m) {
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j - 1] + a[j - 1]*b[i - 1], dp[i][j - 1]);
            }
        }
        
        return dp[m][n];
    }
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
	    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(n-m+1, -1)));
		// return solve_mem(0, 0, n-m, a, b, n, m, dp);

        return solve_tab(a, b, n, m);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends