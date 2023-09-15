// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    // TC = O(N * sum)
    // SC = O(N * sum)
    int solve_mem(int N, int arr[], int index, int target, vector<vector<int>>& dp) {
        // base case
        if (index == N) {
            if (target == 0) return 1;
            return 0;
        }
        
        if (target < 0) return 0;
        
        if (dp[index][target] != -1) return dp[index][target];
        
        int incl = solve_mem(N, arr, index + 1, target - arr[index], dp);
        int excl = solve_mem(N, arr, index + 1, target, dp);
        
        return dp[index][target] = (incl + excl);
    }

    // TC = O(N * sum)
    // SC = O(N * sum)   
    int solve_tab(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) sum += arr[i];
        
        if (sum % 2 == 1) return 0;
        else sum /= 2; 
        
        vector<vector<int>> dp(N+1, vector<int>(sum+1, 0));
        for (int target = 0; target <= sum; target++) {
            dp[N][target] = 0;
        }
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;
        }
        
        for (int index = N - 1; index >= 0; index--) {
            for (int target = 1; target <= sum; target++) {
                
                int incl = (arr[index] <= target) ? dp[index + 1][target - arr[index]] : 0;
                int excl = dp[index + 1][target];
                
                dp[index][target] = (incl + excl);
            }
        }
        return dp[0][sum];
    }

    // TC = O(N * sum)
    // SC = O(sum)
    int solve_so(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) sum += arr[i];
        
        if (sum % 2 == 1) return 0;
        else sum /= 2; 
        
        vector<int> curr(sum+1, 0);
        vector<int> next(sum+1, 0);
        for (int target = 0; target <= sum; target++) {
            next[target] = 0;
        }
        for (int i = 0; i <= N; i++) {
            curr[0] = 1;
        }
        
        for (int index = N - 1; index >= 0; index--) {
            for (int target = sum; target > 0; target--) {
                
                int incl = (arr[index] <= target) ? next[target - arr[index]] : 0;
                int excl = next[target];
                
                curr[target] = (incl + excl);
            }
            next = curr;
        }
        return curr[sum];
    }
    
    int solveMem(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        if (sum % 2 == 1) return 0;
        else sum /= 2; 
        
        vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
        return solve_mem(N, arr, 0, sum, dp);
    }
public:
    int equalPartition(int N, int arr[])
    {   
        // return solveMem(N, arr);
        
        // return solve_tab(N, arr);
        
        return solve_so(N, arr);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends