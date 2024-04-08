// https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    private:
    typedef long long ll;
    
    // TC : O(N * N)
    // SC : O(N * N)
    ll mem(int arr[], int n, int i, int j, vector<vector<int>>& dp) {
        if (i  > j) return 0;
        if (j == i) return arr[i];
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        ll op1 = arr[i] + min(mem(arr, n, i + 2, j, dp), mem(arr, n, i + 1, j - 1, dp));
        ll op2 = arr[j] + min(mem(arr, n, i, j - 2, dp), mem(arr, n, i + 1, j - 1, dp));
        
        return dp[i][j] = max(op1, op2);
    }
    
    // TC : O(N * N)
    // SC : O(N * N)
    ll tab(int n, int arr[]) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        for(int j = 0; j < n; j++){
            for(int i = j; i >= 0; i--){
                if(i == j){
                    dp[i][j] = arr[i];
                }
                else{
                    ll op1 = arr[i] + min((i+2 <= j ? dp[i+2][j] : 0), (i+1 <= j-1 ? dp[i+1][j-1] : 0));
                    ll op2 = arr[j] + min((i <= j-2 ? dp[i][j-2] : 0), (i+1 <= j-1 ? dp[i+1][j-1] : 0));
                    dp[i][j] = max(op1, op2);
                }
            }
        }
        
        return dp[0][n-1];
    }
    public:
    ll maximumAmount(int n, int arr[]){
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return mem(arr, n, 0, n - 1, dp);
        
        return tab(n, arr);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends