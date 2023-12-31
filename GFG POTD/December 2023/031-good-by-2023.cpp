// https://www.geeksforgeeks.org/problems/good-by-2023/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    private:
    int t[367][2025];
    
    // TC : O(2^N)
    // SC : O(N)
    int solve_rec(int n, int coins[], int idx, int sum) {
        if (idx == n) {
            return sum > 0 && (sum % 20 == 0 || sum % 24 == 0 || sum == 2024);
        }
        if (sum > 0 && (sum % 20 == 0 || sum % 24 == 0 || sum == 2024)) {
            return 1;
        }
        
        int include = solve_rec(n, coins, idx+1, sum + coins[idx]);
        int exclude = solve_rec(n, coins, idx+1, sum);
            
        return (include | exclude);
    }
    
    // TC : O(N*Sum)
    // SC : O(N*Sum)
    int solve_mem(int n, int coins[], int idx, int sum) {
        if (idx == n) {
            return sum > 0 && (sum % 20 == 0 || sum % 24 == 0 || sum == 2024);
        }
        if (sum > 0 && (sum % 20 == 0 || sum % 24 == 0 || sum == 2024)) {
            return 1;
        }
        if (t[idx][sum] != -1)
            return t[idx][sum];
        
        int include = solve_mem(n, coins, idx+1, sum + coins[idx]);
        int exclude = solve_mem(n, coins, idx+1, sum);
            
        return t[idx][sum] = (include | exclude);
    }
    
    // TC : O(N*Sum)
    // SC : O(N*Sum)
    int solve_tab(int N, int coins[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += coins[i];
        }
        
        vector<vector<int>> dp(N+1, vector<int>(sum+1, 0));
        
        for (int idx = 0; idx <= N; idx++) {
            for (int s = 0; s <= sum; s++) {
                if (s > 0 && (s % 20 == 0 || s % 24 == 0 || s == 2024)) {
                    dp[idx][s] = 1;
                }
            }
        }
        
        for (int idx = N - 1; idx >= 0; idx--) {
            for (int s = 0; s <= sum; s++) {
                int include = 0, exclude = 0;
                if (s + coins[idx] <= sum) {
                    include = dp[idx+1][s + coins[idx]];
                }
                exclude = dp[idx+1][s];
                    
                dp[idx][s] = (include | exclude);
            }
        }
        
        return dp[0][0];
    }
    
    // TC : O(N*Sum)
    // SC : O(2sum) ~ O(sum)
    int solve_so(int N, int coins[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += coins[i];
        }
        
        vector<vector<int>> dp(2, vector<int>(sum+1, 0));
        
        for (int idx = 0; idx <= N; idx++) {
            for (int s = 0; s <= sum; s++) {
                if (s > 0 && (s % 20 == 0 || s % 24 == 0 || s == 2024)) {
                    dp[idx%2][s] = 1;
                }
            }
        }
        
        for (int idx = N - 1; idx >= 0; idx--) {
            for (int s = 0; s <= sum; s++) {
                int include = 0, exclude = 0;
                if (s + coins[idx] <= sum) {
                    include = dp[(idx+1)%2][s + coins[idx]];
                }
                exclude = dp[(idx+1)%2][s];
                    
                dp[idx%2][s] = (include | exclude);
            }
        }
        
        return dp[0][0];
    }
    public:
    int isPossible(int N , int coins[]) 
    {
        // return solve_rec(N, coins, 0, 0);
        
        // memset(t, -1, sizeof(t));
        // return solve_mem(N, coins, 0, 0);
        
        // return solve_tab(N, coins);
        
        return solve_so(N, coins);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends