// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        const int mod = 1e9 + 7;
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] = (dp[i] + (dp[j] * dp[i-j-1]) % mod) % mod;
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends