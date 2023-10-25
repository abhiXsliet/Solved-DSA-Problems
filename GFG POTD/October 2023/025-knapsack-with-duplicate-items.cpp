// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dp[1001][1001];

    // TC = O(2^N)
    // SC = O(N) -> recursion depth
    int solve_rec(int val[], int wt[], int N, int capacity, int idx) {
        if (idx == N || capacity == 0) return 0;
        
        int take = 0;
        if (wt[idx] <= capacity) {
            take = val[idx] + solve_rec(val, wt, N, capacity - wt[idx], idx);
        }
        
        int not_take = solve_rec(val, wt, N, capacity, idx+1);
        
        return max(take, not_take);
    }

    // TC = O(N*W)
    // SC = O(N*W) 
    int solve_mem(int val[], int wt[], int N, int capacity, int idx) {
        if (idx == N || capacity == 0) 
            return 0;
        
        if (dp[capacity][idx] != -1) 
            return dp[capacity][idx];
        
        int take = 0;
        if (wt[idx] <= capacity) {
            take = val[idx] + solve_mem(val, wt, N, capacity - wt[idx], idx);
        }
        
        int not_take = solve_mem(val, wt, N, capacity, idx+1);
        
        return dp[capacity][idx] = max(take, not_take);
    }

    // TC = O(N*W)
    // SC = O(N*W) 
    int solve_tab(int N, int W, int val[], int wt[]) {
        vector<vector<int>> dp(W + 1, vector<int>(N + 1, 0));
        
        for(int i = 0; i < N; i++) {
            dp[0][i] = 0;
        }
        
        for (int capacity = 0; capacity <= W; capacity++) {
            for (int idx = N-1; idx >= 0; idx--) {
                int take = 0;
                if (wt[idx] <= capacity) {
                    take = val[idx] + dp[capacity - wt[idx]][idx];
                }
                
                int not_take = dp[capacity][idx + 1];
                
                dp[capacity][idx] = max(take, not_take);
            }
        }
        
        return dp[W][0];
    }
    
    // TC = O(N*W)
    // SC = O(W)
    int solve_so(int N, int W, int val[], int wt[]) {
        vector<int> curr(1001, 0);
        vector<int> prev(1001, 0);
        
        for(int i = 0; i < N; i++) {
            curr[i] = 0;
        }
        
        
        for (int idx = N-1; idx >= 0; idx--) {
            for (int capacity = 0; capacity <= W; capacity++) {
                int take = 0;
                if (wt[idx] <= capacity) {
                    take = val[idx] + prev[capacity - wt[idx]];
                }
                
                int not_take = curr[capacity];
                
                prev[capacity] = max(take, not_take);
            }
            curr = prev;
        }
        
        return curr[W];
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // return solve_rec(val, wt, N, W, 0);
        
        
        // memset(dp, -1, sizeof(dp));
        // return solve_mem(val, wt, N, W, 0);
        
        
        // return solve_tab(N, W, val, wt);
        
        
        return solve_so(N, W, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends