// https://www.geeksforgeeks.org/problems/cutted-segments1642/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
    private:
    int dp[10001];
    
    // TC : O(N)
    // SC : O(N)
    int mem(int n, int x, int y, int z) {
        if (n == 0) return 0;
        
        if (dp[n] != -1) return dp[n];
        
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        if (n - x >= 0) 
            a = 1 + mem(n - x, x, y, z);
        if (n - y >= 0)
            b = 1 + mem(n - y, x, y, z);
        if (n - z >= 0)
            c = 1 + mem(n - z, x, y, z);
        
        return dp[n] = max({a, b, c});
    }
    
    int tab(int N, int x, int y, int z) {
        vector<int> dp(N + 1, INT_MIN);
        dp[0] = 0;  // Base case: no cuts needed for length 0
    
        for (int n = 1; n <= N; n++) {
            if (n - x >= 0 && dp[n - x] != INT_MIN)
                dp[n] = max(dp[n], 1 + dp[n - x]);
                
            if (n - y >= 0 && dp[n - y] != INT_MIN)
                dp[n] = max(dp[n], 1 + dp[n - y]);
                
            if (n - z >= 0 && dp[n - z] != INT_MIN)
                dp[n] = max(dp[n], 1 + dp[n - z]);
        }
        
        return dp[N] < 0 ? 0 : dp[N];
    }

    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // memset(dp, -1, sizeof(dp));
        // int result = mem(n, x, y, z);
        // return result < 0 ? 0 : result;
        
        return tab(n, x, y, z);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends