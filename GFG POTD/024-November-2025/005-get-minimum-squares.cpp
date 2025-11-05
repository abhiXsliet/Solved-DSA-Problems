// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1/




#include <bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution{
    int solveMem(int n, vector<int>& dp) {
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
            
        int ans = n;
        for(int i = 1; i * i <= n; i ++) {
            ans = min(ans, 1+solveMem(n - i * i, dp));
        }
        dp[n] = ans;
        return ans;
    }
    
    int solveTab(int n) {
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;
        
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j * j <= n; j ++) {
                int temp = j * j;
                if(i-temp >= 0)    
                    dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
        return dp[n];
    }
    
	public:
	int minSquares(int n)
	{
	   vector<int> dp(n+1, -1);
	   return solveMem(n, dp);
	   
	   //return solveTab(n);
	}
};