// https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution{
    // TC : O(N*M)
    // SC : O(N*M)
    int solveMem(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&dp, int &maxi) {
        if(i >= mat.size() || j >= mat[0].size())
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];

        int right    = solveMem(i, j+1, mat, dp, maxi);
        int diagonal = solveMem(i+1, j+1, mat, dp, maxi);
        int down     = solveMem(i+1, j, mat, dp, maxi);
        
        if(mat[i][j] == 1) {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi     = max(maxi, dp[i][j]);
            return dp[i][j];
        } else {
            return dp[i][j] = 0;
        }
    }

    // TC : O(N*M)
    // SC : O(N*M)
    int tab_1(int row, int col, vector<vector<int>>& mat, int& maxi) {
        vector<vector<int>>dp(row + 1, vector<int>(col + 1, 0));
        
        for(int i = row - 1; i >= 0; i --) {
            for(int j = col - 1; j >= 0; j --) {
                
                int right    = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down     = dp[i+1][j];
                
                if(mat[i][j] == 1) {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi     = max(maxi, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    
    // TC : O(N*M)
    // SC : O(1)
    int tab_2(int row, int col, vector<vector<int>>& mat, int& maxi) {
        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                
                if(i>0 && j>0 && mat[i][j]){
                    int right    = mat[i][j-1];
                    int diagonal = mat[i-1][j-1];
                    int down     = mat[i-1][j];
                    
                    mat[i][j]    = 1+ min(right, min(diagonal, down));
                }                    
                maxi = max(maxi, mat[i][j]);
            }
        }
        return maxi;
    }
    
    // TC : O(N*M)
    // SC : O(M) Where M = cols
    int so_1(int row, int col, vector<vector<int>>& mat, int& maxi) {
        vector<int> curr(col + 1, 0);
        vector<int> next(col + 1, 0);
        
        for(int i = row - 1; i >= 0; i --){
            for(int j = col - 1; j >= 0; j --) {
                
                int right    = curr[j+1];
                int diagonal = next[j+1];
                int down     = next[j];
                
                if(mat[i][j] == 1) {
                    curr[j]  = 1 + min(right, min(diagonal, down));
                    maxi     = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
    
    // TC : O(N*M)
    // SC : O(501) 
    int so_2(int row, int col, vector<vector<int>> &mat, int &maxi) {
        vector<int> curr(500, 0);
        vector<int> next(501, 0);
        
        for(int i = row - 1; i >= 0; i --){
            for(int j = col - 1; j >= 0; j --) {
                
                int right    = curr[j+1];
                int diagonal = next[j+1];
                int down     = next[j];
                
                if(mat[i][j] == 1) {
                    curr[j]  = 1 + min(right, min(diagonal, down));
                    maxi     = max(maxi, curr[j]);
                    
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
    
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // solveMem(0, 0, mat, dp, maxi);   // Memoization Aproach

        // tab_1(n, m, mat, maxi);          // Tabulation Approach - 1

        // tab_2(n, m, mat, maxi);          // Tabulation Approach - 2

        // so_1(n, m, mat, maxi);           // Space Optimization

        // so_2(n, m, mat, maxi);           // Space Optimization
       
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends