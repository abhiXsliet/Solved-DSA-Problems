// https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1



//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
private:
    int M = 1000000007;
    
    // TC : O(X * Y)
    // SC : O(X * Y)
    int mem(int x, int y, vector<vector<int>>& dp) {
        if (x == 0 && y == 0) return 1;
        
        if (dp[x][y] != -1) return dp[x][y];
        
        int cnt = 0;
        if (x > 0) 
            cnt = (cnt % M +  mem(x - 1, y, dp) % M) % M;
            
        if (y > 0)
            cnt = (cnt % M +  mem(x, y - 1, dp) % M) % M;
        
        return dp[x][y] = cnt;
    }
    
    // TC : O(X * Y)
    // SC : O(X * Y)
    int tab(int x, int y) {
        int dp[501][501] = {{0}};
        
        dp[0][0] = 1;
        for (int i = 1; i <= x; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= y; i++) {
            dp[0][i] = 1;
        }
        
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                
                dp[i][j] = (dp[i - 1][j] % M + dp[i][j - 1] % M) % M;
            }
        }
        return dp[x][y];
    }
public:
    int ways(int x, int y)
    {
        // vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        // return mem(x, y, dp);
        
        return tab(x, y);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends