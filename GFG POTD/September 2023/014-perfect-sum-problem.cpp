// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
#define mod 1000000007
private:
    // TC = O(sum * N)
    // SC = O(sum * N)
    int solve_mem(int arr[], int n, int sum, int idx, vector<vector<int>>& dp) {
        if (idx == n) {
            return sum == 0 ? 1 : 0;
        }
        
        if (sum < 0) return 0;
        
        if(dp[sum][idx] != -1) return dp[sum][idx];
        
        int incl = solve_mem(arr, n, sum-arr[idx], idx+1, dp) % mod;
        int excl = solve_mem(arr, n, sum, idx+1, dp) % mod;
        
        return dp[sum][idx] = (incl + excl) % mod;
    }

public:
	int perfectSum(int arr[], int n, int sum)
	{   
	    // Recursion + Memoization
        vector<vector<int>> dp(sum+1, vector<int>(n+1, -1));
        return solve_mem(arr, n, sum, 0, dp);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends