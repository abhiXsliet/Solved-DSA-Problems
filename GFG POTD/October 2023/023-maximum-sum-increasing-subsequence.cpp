// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int solve_rec(int arr[], int n, int idx, int prev) {
        if (idx >= n)
            return 0;
        
        int incl = 0;
        if (arr[idx] > prev)
            incl = arr[idx] + solve_rec(arr, n, idx+1, arr[idx]);

        int excl = 0 + solve_rec(arr, n, idx+1, prev);
        
        return max(incl, excl);
    }
    
    int solve_mem(int arr[], int n, int idx, int prev, vector<vector<int>>& dp) {
        if (idx >= n)
            return 0;
            
        if (dp[idx+1][prev+1] != -1)
            return dp[idx+1][prev+1];
        
        int incl = 0;
        if (prev == -1 || arr[prev] < arr[idx]) {
            incl = arr[idx] + solve_mem(arr, n, idx+1, idx, dp); 
        }
        int excl = solve_mem(arr, n, idx+1, prev, dp);
        
        return dp[idx+1][prev+1] = max(incl, excl);
    }
    
    int solve_tab(int arr[],int n){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = n-1; i >= 0; i--){
            for(int prev = i-1; prev >= -1; prev--){
                
                int include = 0;
                if(prev == -1 || arr[prev] < arr[i]) 
                    include = arr[i] + dp[i+1][i+1];
            
                int exclude = dp[i+1][prev+1];
             
                dp[i][prev+1] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
    
    int solve_so(int arr[],int n){
        
        vector<int> next(n+1,0);
        vector<int>curr(n+1,0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int prev = i-1; prev >= -1; prev--) {
        
                int include = 0;
                if(prev == -1 || arr[prev] < arr[i]) 
                    include = arr[i] + next[i+1];
            
                int exclude = next[prev+1];
             
                curr[prev+1]=max(include, exclude);
            }
            next = curr;
        }
        return curr[0];
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	   // return solve_rec(arr, n, 0, INT_MIN);
	   
	   //vector<vector<int>> dp(n+1, vector<int>(n, -1));
	   //return solve_mem(arr, n, 0, -1, dp);
	   
	   //return solve_tab(arr, n);
	   
	   return solve_so(arr, n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends