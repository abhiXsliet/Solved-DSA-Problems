// https://practice.geeksforgeeks.org/problems/coin-change2448/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    #define ll long long int
  private:
    // TC = O(2^N)
    // SC = O(N) -> due to recursive call stack
    ll solveRec(int coins[], int N, int sum, int i) {
        // base case
        if (i == N) return 0;
        if (sum == 0) return 1;
        
        int include = 0;
        if(sum >= coins[i]) {
            include = solveRec(coins, N, sum - coins[i], i);
        }
        
        int exclude = solveRec(coins, N, sum, i+1);
        
        return (include + exclude);
    }
    
    // TC = O(N * sum)
    // SC = O(N * sum)
    ll solveMem(int coins[], int N, int sum, int i, vector<vector<ll>>& dp) {
        // base case
        if (i == N) return 0;
        if (sum == 0) return 1;
        
        if(dp[sum][i] != -1)
            return dp[sum][i];
        
        ll include = 0;
        if(sum >= coins[i]) {
            include = solveMem(coins, N, sum - coins[i], i, dp);
        }
        
        ll exclude = solveMem(coins, N, sum, i+1, dp);
        
        return dp[sum][i] = (include + exclude);
    }
    
    // TC = O(N * sum)
    // SC = O(N * sum)
    ll solveTab(int coins[], int N, int sum) {
        vector<vector<ll>> dp(sum+1, vector<ll>(N+1, 0));
        
        for(int i = 0; i < N; i++) {
            dp[0][i] = 1;
        }
        
        for(int i = N - 1; i >= 0; i--) {
            for(int j = 1; j <= sum; j++) {
                ll include = 0;
                if(j >= coins[i]) {
                    include = dp[j - coins[i]][i];
                }
                
                ll exclude = dp[j][i+1];
                
               dp[j][i] = (include + exclude);
            }
        }
        return dp[sum][0];
    }
    
    // TC = O(N * sum)
    // SC = O(N)
    ll solveSO(int coins[], int N, int sum) {
        vector<ll> curr(sum+1, 0);
        vector<ll> next(sum+1, 0);
        
        curr[0] = 1;
        
        for(int i = N - 1; i >= 0; i--) {
            for(int j = 1; j <= sum; j++) {
                ll include = 0;
                if(j >= coins[i]) {
                    include = curr[j - coins[i]];
                }
                
                ll exclude = next[j];
                
               curr[j] = (include + exclude);
            }
            next = curr;
        }
        return next[sum];
    }
    
  public:
    long long int count(int coins[], int N, int sum) {
        // // Recursion -> TLE
        // return solveRec(coins, N, sum, 0);
        
        
        // // Recursion + Memoization
        // vector<vector<ll>> dp(sum+1, vector<ll>(N+1, -1));
        // return solveMem(coins, N, sum, 0, dp);
        
        
        // // Tabulation
        // return solveTab(coins, N, sum);
        
        
        // Space Optimization
        return solveSO(coins, N, sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends