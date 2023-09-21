// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    private:
    // TC = O(2^N)
    // SC = O(N) due to max recursion depth on call stack
    int solve_rec(int arr[], int n, int index) {
        // base case
        if (index >= n)
            return 0;
            
        int include = arr[index] + solve_rec(arr, n, index+2);
        int exclude = 0 + solve_rec(arr, n, index+1);
        
        return max(include, exclude);
    }
    
    // TC = O(N)
    // SC = O(N)
    int solve_mem(int arr[], int n, int index, vector<int>& dp) {
        // base case
        if (index >= n)
            return 0;
        
        if (dp[index] != -1) return dp[index];
            
        int include = arr[index] + solve_mem(arr, n, index+2, dp);
        int exclude = 0 + solve_mem(arr, n, index+1, dp);
        
        return dp[index] = max(include, exclude);
    }
    
    // TC = O(N)
    // SC = O(N)    
    int solve_tab(int arr[], int n) {
        vector<int> dp(n+2, 0);
        
        for (int index = n - 1; index >= 0; index--) {
            int include = arr[index] + dp[index+2];
            int exclude = 0 + dp[index+1];
            
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // return solve_rec(arr, n, 0);
        
        
        // Memoizatioin
        // vector<int> dp(n+1, -1);
        // return solve_mem(arr, n, 0, dp);
        
        
        // Tabulation
        return solve_tab(arr, n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends