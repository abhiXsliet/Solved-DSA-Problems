// https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  #define mod 1000000007
  private:
    // TC = O(N)
    // SC = O(N)
    int solve(int n, vector<int>& dp) {
        // base case
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        
        if (dp[n] != -1) return dp[n];
        
        int ans = ( solve(n - 1, dp) + solve(n - 2, dp) ) % 1000000007;
        return dp[n] = ans;
    }
    
    // TC = O(N)
    // SC = O(1)
    int solveSO(int n) {
        if (n == 0) return 0;
        
        int a = 1, b = 1;
        n = n - 2;
        while(n-- > 0) {
            int c = ( a + b ) % mod;
            a = b;
            b = c;
        }
        return b;
    }
    
  public:
    int nthFibonacci(int n){
        // Approach - 1
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);
        
        
        // Approach - 2
        return solveSO(n);
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends