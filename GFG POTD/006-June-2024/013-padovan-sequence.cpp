// https://www.geeksforgeeks.org/problems/padovan-sequence2855/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
    private:
    int M = 1e9 + 7;
    int t[1000001];
    
    // TC : O(N) -> Runtime error due to long array size
    // SC : O(N)
    int mem(int n) {
        if (n == 0 || n == 1 || n == 2) 
            return 1;
        
        if (t[n] != -1) return t[n];
            
        int ans = (mem(n - 2) % M + mem(n - 3) % M) % M;
        return t[n] = ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    int tab(int n) {
        vector<int> dp(n+1, 0);
        
        dp[0] = dp[1] = dp[2] = 1;
        
        for (int i = 3; i <= n; i ++) {
            dp[i] = (dp[i - 2] % M + dp[i - 3] % M) % M;
        }
        return dp[n];
    }
    public:
    int padovanSequence(int n)
    {
        memset(t, -1, sizeof(t));
        // return mem(n);
        
        return tab(n);
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
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends