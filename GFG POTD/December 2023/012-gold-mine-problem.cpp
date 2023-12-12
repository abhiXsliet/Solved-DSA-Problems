// https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    // TC = O(N*M)
    // SC = O(N*M)
    int solve_approach_1(int n, int m, vector<vector<int>>& M) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = M[i][m - 1];
        }
        
        for (int j = m - 2; j >= 0; j--) { // cols
            for (int i = 0; i <  n; i++) { // rows
                dp[i][j] = dp[i][j + 1];   // from right
                
                if (i - 1 >= 0) // diagonally up towards right
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
                
                if (i + 1 <  n) // diagonally dow towards right
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1]);
                    
                dp[i][j] += M[i][j]; // add val of current position
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i][0]);
        }
        
        return res;
    }
    
    // TC = O(N*M)
    // SC = O(1)
    int solve_approach_2(int n, int m, vector<vector<int>>& M) {
        int res = 0;
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int maxi = INT_MIN;
                if (i - 1 >= 0 && j - 1 >= 0) 
                    maxi = max(maxi, M[i - 1][j - 1]);
                if (j - 1 >= 0)
                    maxi = max(maxi, M[i][j - 1]);
                if (i + 1 < n && j - 1 >= 0)
                    maxi = max(maxi, M[i + 1][j - 1]);
                
                M[i][j] += maxi;
                res      = max (res, M[i][j]);
            }
        }
        return res;
    }
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // return solve_approach_1(n, m, M);
        
        return solve_approach_2(n, m, M);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends