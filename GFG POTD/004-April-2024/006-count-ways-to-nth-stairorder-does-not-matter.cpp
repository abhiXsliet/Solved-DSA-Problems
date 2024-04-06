// https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    typedef long long ll;
    
    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    ll solve(int n) {
        if (n == 0) return 1;
        if (n  < 0) return 0;
        
        return 1 + solve(n - 2);
    }
    
    // TC : O(N)
    // SC : O(N)
    ll tab(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 1 + dp[i - 2];
        }
        return dp[n];
    }
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        // return solve(n);
        
        // return tab(n);
        
        return (n/2) + 1;
    }
};


//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends