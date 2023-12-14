// https://www.geeksforgeeks.org/problems/painting-the-fence3727/1



//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int MOD = 1e9 + 7;
    
    int add(int a, int b) {
        return (a%MOD + b%MOD)%MOD;
    }
    
    int mul(int a, int b) {
        return ((a%MOD)*1LL * (b%MOD))%MOD;
    }
    
    //Time Complexity is expontential for this solution
    long long solve_rec(int n, int k) {
        //base case
        if(n == 1)
            return k;
        if(n == 2)
            return add(k, mul(k,(k-1)));
        
        long long ans = add( mul(solve_rec(n-2, k), (k-1)), mul(solve_rec(n-1, k), (k-1)) );
        return ans;
    }
    
    //TC : O(N)
    //SC : O(N)
    long long solve_mem(int n, int k, vector<int>& dp) {
        //base case
        if(n == 1)
            return k;
        if(n == 2)
            return add(k, mul(k, k-1));
    
        //step-3
        if(dp[n] != -1)
            return dp[n];
    
        //step-2
        dp[n] = add( mul(solve_mem(n-2, k, dp), k-1), mul(solve_mem(n-1, k, dp), k-1) );
        return dp[n];
    }
    
    //TC : O(N)
    //SC : O(N) + O(N) => Recursion Depth + DP-array space
    long long solve_tab(int n, int k) {
        //step-1
        vector<int>dp(n+1, 0);
        //step-2
        dp[1] = k;
        dp[2] = add(k, mul(k, k-1));
        //step-3
        for(int i=3; i<=n; i++) {
            dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
        }
        return dp[n];
    }
    
    //TC : O(N)
    //SC : O(1)
    long long solve_so(int n, int k) {
        if (n == 1) return k;
        else {
            //step-1
            long long prev2 = k;
            long long prev1 = add(k, mul(k, k-1));
            //step-2
            for(int i=3; i<=n; i++) {
                long long ans = add(mul(prev1, k - 1), mul(prev2, k - 1));
                prev2 = prev1;
                prev1 = ans;
            }
            //step-3
            return prev1;
        }
    }
    public:
    long long countWays(int n, int k){
        // return solve_rec(n, k); 
        
        // vector<int> dp(n+1, -1);
        // return solve_mem(n, k, dp);
        
        // return solve_tab(n, k);
        
        return solve_so(n, k);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends