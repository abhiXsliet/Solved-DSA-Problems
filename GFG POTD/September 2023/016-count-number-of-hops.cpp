// https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
#define mod 1000000007
private:
    // TC = O(N), SC = O(N)
    long long solve_mem(int n, int arr[], vector<int>& dp) {
        // base case
        if (n < 0) return 0;
        if (n == 0) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        long long first  = solve_mem(n - arr[0], arr, dp) % mod;
        long long second = solve_mem(n - arr[1], arr, dp) % mod;
        long long third  = solve_mem(n - arr[2], arr, dp) % mod;
        
        return dp[n] = (first + second + third) % mod;
    }
    
    // TC = O(N), SC = O(N)
    long long solve_tab(int n) {
        int arr[3] = {1, 2, 3};
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                if(i >= arr[j]) {
                    dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
                }
            }
        }
        return dp[n];
    }
        
    // TC = O(N), SC = O(1)
    // Tribonacci sequence or series
    long long solve_optimal(int n) {
        
        long long a = 1, b = 2, c = 4;
        
        if (n == 1) return a;
        if (n == 2) return b;
        if (n == 3) return c;
        
        long long ans = 0;
        for (int i = 4; i <= n; i++) {
            ans = ((a % mod + b % mod)% mod + c % mod) % mod;
            a = b;
            b = c;
            c = ans;
        }
        return ans % mod;
    }
    
public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {   
        int arr[3] = {1, 2, 3};
        
        // Memoization
        // vector<int> dp(n+1, -1);
        // return solve_mem(n, arr, dp);
        
        // Tabulation
        // return solve_tab(n);
        
        // Optimal Approach
        return solve_optimal(n);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0; 
}
// } Driver Code Ends