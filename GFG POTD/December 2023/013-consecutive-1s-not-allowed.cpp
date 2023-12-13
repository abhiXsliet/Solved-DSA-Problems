// https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// } Driver Code Ends

//User function template for C++
class Solution{
private:
    int M = 1e9 + 7;
    // TC = O(N)
    // SC = O(N)
    ll solve_mem(int n, vector<int>& dp) {
        if (n == 1) return 2;
        if (n == 2) return 3;
        
        if (dp[n] != -1) return dp[n];
        
        ll ans = 0;
        ans = ( solve_mem(n - 1, dp) + solve_mem(n - 2, dp) ) % M;
        dp[n] = ans;
        
        return ans;
    }
    
    // TC = O(N)
    // SC = O(N)
    ll solve_tab(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 2;
        dp[2] = 3;
    
        for (int i = 3; i <= n; i++) {
            dp[i] = ( dp[i - 1] + dp[i - 2] ) % M;
        }
        
        return dp[n];
    }
    
    // TC = O(N)
    // SC = O(1)
    ll solve_so(int n) {
        if (n == 1) return 2;
        if (n == 2) return 3;
        
        int prev_prev = 2;
        int prev      = 3;
        int curr      = 0;
    
        for (int i = 3; i <= n; i++) {
            curr = ( prev_prev + prev ) % M;
            prev_prev = prev;
            prev      = curr;
        }
        
        return curr;
    }
public:
	// #define ll long long
	ll countStrings(int n) {
	   // vector<int> dp(n+1, -1);
	   // return solve_mem(n, dp);
	   
	   //return solve_tab(n);
	   
	   return solve_so(n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends