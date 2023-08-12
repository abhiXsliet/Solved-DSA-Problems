// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    // TC = O( 2 ^ n )
    // SC = O( n ) -> due to recursive call stack
    int solveRec(int n, int a[], int curr, int prev) {
        // base case
        if (curr == n)
            return 0;
        
        int include = 0;
        if (prev == -1 || a[curr] > a[prev]) 
            include = 1 + solveRec(n, a, curr+1, curr);
        
        int exclude = solveRec(n, a, curr+1, prev);
        
        return max(include, exclude);
    }
      
    // TC = O( n * n )
    // SC = O( n * n )
    int solveMem(int n, int a[], int curr, int prev, vector<vector<int>>& dp) {
        // base case
        if (curr == n)
            return 0;
            
        if (dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        int include = 0;
        if (prev == -1 || a[curr] > a[prev]) 
            include = 1 + solveMem(n, a, curr+1, curr, dp);
        
        int exclude = solveMem(n, a, curr+1, prev, dp);
        
        return dp[curr][prev+1] = max(include, exclude);
    }
    
    int solveTab(int n, int a[]) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr = n - 1; curr >= 0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev]) 
                    include = 1 + dp[curr+1][curr+1];
                
                int exclude = dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    
    // TC = O( n * n )
    // SC = O( n )
    int solveSO(int n, int a[]) {
        vector<int> currN(n+1, 0);
        vector<int> nextN(n+1, 0);
        
        for(int curr = n - 1; curr >= 0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev]) 
                    include = 1 + nextN[curr+1];
                
                int exclude = nextN[prev+1];
                
                currN[prev+1] = max(include, exclude);
            }
            nextN = currN;
        }
        return nextN[0];
    }
    
    // TC = O( n * log(n) )
    // SC = O( n )
    int solveOptimal(int n, int a[]) {
        if (n == 0)
            return 0;
            
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i = 1; i < n; i++) {
            if(a[i] > ans.back()) {
                ans.push_back(a[i]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // Recursive Solution -> TLE
        // return solveRec(n, a, 0, -1);
        
        // // Recursion + Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(n, a, 0, -1, dp);
        
        
        // Tabulation
        // return solveTab(n, a);
        
        
        // Space-Optimization
        // return solveSO(n, a);
        
        
        
        // Optimal
        return solveOptimal(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends