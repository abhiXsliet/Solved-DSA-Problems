// https://www.geeksforgeeks.org/problems/trail-of-ones3242/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int M = 1e9 + 7;
    
    // TC : O(2^N)
    // SC : O(N) -> Recursive Depth
    int solve(int n) {
        if (n == 2) return 1;
        
        int prev_1 = 0, prev_2 = 1, result = 0;
        
        for (int i = 3; i <= n; i ++) {
            int sum = (prev_1 + prev_2) % M;
            prev_1 = prev_2;
            prev_2 = sum;
            result = (2*solve(i - 1) % M + sum) % M ;
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    int solveTab(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        
        int prev_1 = 0, prev_2 = 1;
        
        for (int i = 3; i <= n; i ++) {
            int sum = (prev_1 + prev_2) % M;
            prev_1 = prev_2;
            prev_2 = sum;
            dp[i] = (2 * dp[i - 1] % M + sum) % M ;
        }
        return dp[n];
    }
    
    // TC : O(N)
    // SC : O(1)
    int solveSo(int n) {
        if (n == 2) return 1;
        int prev_1 = 0, prev_2 = 1, result = 1;
        
        for (int i = 3; i <= n; i ++) {
            int sum = (prev_1 + prev_2) % M;
            prev_1 = prev_2;
            prev_2 = sum;
            result = (2 * result % M + sum) % M ;
        }
        return result;
    }
  public:
    int numberOfConsecutiveOnes(int n) {
        // return solve(n); // TLE
        
        // return solveTab(n);
        
        return solveSo(n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}
// } Driver Code Ends