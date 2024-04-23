// https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int solve(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        
        if (dp[n] != -1) return dp[n];
        
        int ans = ( solve(n - 1, dp) + solve(n - 2, dp) ) % 1000000007;
        return dp[n] = ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    int tab(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
    }

    // TC : O(N)
    // SC : O(1)
    int so(int n) {
        int prev1 = 0;
        int prev2 = 1;
        
        for (int i = 2; i <= n; i++) {
            int curr = (prev1 + prev2) % 1000000007;
            prev1  = prev2;
            prev2  = curr;
        }
        return prev2;
    }
  public:
    int firstElement(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);
        
        // return tab(n);
        
        return so(n);
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}
// } Driver Code Ends