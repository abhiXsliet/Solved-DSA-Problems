// https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:   
    // TC : O(M * N)
    // SC : O(M * N) -> Memoization array
    int dfs(vector<vector<int>>& arr, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) {
            return arr[i][j] > 0 ? 1 : abs(arr[i][j]) + 1;
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        if (j + 1 < n) {
            int right = - arr[i][j] + dfs(arr, m, n, i, j + 1, dp);
            ans       = min(ans, right);
        }
        if (i + 1 < m) {
            int down = - arr[i][j] + dfs(arr, m, n, i + 1, j, dp);
            ans      = min(ans, down);
        }
        
        return dp[i][j] = ans <= 0 ? 1 : ans;
    }
	public:
	int minPoints(int m, int n, vector<vector<int>> points) { 
	    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
	    return dfs(points, m, n, 0, 0, dp);  
	} 
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends