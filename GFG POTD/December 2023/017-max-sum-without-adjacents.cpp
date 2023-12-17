// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1



//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    // TC : O(N)
    // SC : O(N)
    int solve_mem(int *arr, int n, int idx, vector<int>& dp) {
        if (idx >= n) return 0;
        
        if (dp[idx] != -1) return dp[idx];
        
        int incl = arr[idx] + solve_mem(arr, n, idx+2, dp);
        int excl = solve_mem(arr, n, idx+1, dp);
        
        return dp[idx] = max(incl, excl);
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_tab(int *arr, int n) {
        vector<int> dp(n+1, 0);
        dp[n - 1] = arr[n - 1];
        
        for (int idx = n - 2; idx >= 0; idx--) {
            int incl = arr[idx] + dp[idx+2];
            int excl = dp[idx+1];
            
            dp[idx] = max(incl, excl);
        }
        
        return dp[0];
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_so(int *arr, int n) {
        int curr = arr[n - 1];
        int prev = 0;
        
        for (int idx = n - 2; idx >= 0; idx--) {
            int incl = arr[idx] + prev;
            int excl = curr;
            
            prev = curr;
            curr = max(incl, excl);
        }
        
        return curr;
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   // vector<int> dp(n+1, -1);
	   // return solve_mem(arr, n, 0, dp);
	   
	   
	   //return solve_tab(arr, n);
	   
	   return solve_so(arr, n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends