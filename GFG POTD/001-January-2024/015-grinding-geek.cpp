// https://www.geeksforgeeks.org/problems/grinding-geek/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:
    // TC : O(2^N)
    // SC : O(N) -> Recursive Depth
    int solve_rec(vector<int>& cost, int n, int total, int idx) {
        if (idx == n) return 0;
        
        int include = 0;
        if (cost[idx] <= total) {
            int price = ( (total - cost[idx]) + (0.9 * cost[idx]) );
            include = 1 + solve_rec(cost, n, price, idx + 1);
        }
        int exclude = solve_rec(cost, n, total, idx + 1);
        
        return max(include, exclude);
    }
    
    int t[1001][1001];
    // TC : O(N*total)
    // SC : O(N*total)
    int solve_mem(vector<int>& cost, int n, int total, int idx) {
        if (idx == n) return 0;
        
        if (t[total][idx] != -1)
            return t[total][idx];
            
        int include = 0;
        if (cost[idx] <= total) {
            int price = ( (total - cost[idx]) + (0.9 * cost[idx]) );
            include = 1 + solve_mem(cost, n, price, idx + 1);
        }
        int exclude = solve_mem(cost, n, total, idx + 1);
        
        return t[total][idx] = max(include, exclude);
    }
    
    // TC : O(N*total)
    // SC : O(N*total)
    int solve_tab(vector<int>& cost, int n, int tot) {
        vector<vector<int>> dp(tot+1, vector<int>(n+1, 0));
        
        for (int total = 0; total <= tot; total++) {
            for (int idx = n - 1; idx >= 0; idx--) {
                int include = 0;
                if (cost[idx] <= total) {
                    int price = ( (total - cost[idx]) + (0.9 * cost[idx]) );
                    include = 1 + dp[price][idx + 1];
                }
                int exclude = dp[total][idx + 1];
                
                dp[total][idx] = max(include, exclude);
            }
        }
        return dp[tot][0];
    }
    
    // TC : O(N*total)
    // SC : O(total)
    int solve_so(vector<int>& cost, int n, int tot) {
        vector<int> curr(tot+1, 0);
        vector<int> prev(tot+1, 0);
        
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int total = 0; total <= tot; total++) {
                int include = 0;
                if (cost[idx] <= total) {
                    int price = ( (total - cost[idx]) + (0.9 * cost[idx]) );
                    include = 1 + curr[price];
                }
                int exclude = curr[total];
                
                prev[total] = max(include, exclude);
            }
            curr = prev;
        }
        
        return curr[tot];
    }
    
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        // return solve_rec(cost, n, total, 0);
        
        // memset(t, -1, sizeof(t));
        // return solve_mem(cost, n, total, 0);
        
        // return solve_tab(cost, n, total);
        
        return solve_so(cost, n, total);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends