// https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
    private:
    // TC : O(N1 * N2 * N3)
    // SC : O(N1 * N2 * N3)
    int solveRec_Mem(int n1, int n2, int n3, string& A, string& B, string& C, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if(i >= n1 || j >= n2 || k >= n3) return 0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        if(A[i] == B[j] && B[j] == C[k]) {
            return dp[i][j][k] =  1 + solveRec_Mem(n1, n2, n3, A, B, C, i+1, j+1, k+1, dp);
        } else {
            return dp[i][j][k] = max({ solveRec_Mem(n1, n2, n3, A, B, C, i, j+1, k, dp),
                                       solveRec_Mem(n1, n2, n3, A, B, C, i+1, j, k, dp),
                                       solveRec_Mem(n1, n2, n3, A, B, C, i, j, k+1, dp) });
        }
    }
    
    // TC : O(N1 * N2 * N3)
    // SC : O(N1 * N2 * N3)
    int solve_tab(int n1, int n2, int n3, string& A, string& B, string& C) {
        vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, 0)));
        
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                for (int k = n3 - 1; k >= 0; k--) {
                    
                    if(A[i] == B[j] && B[j] == C[k]) {
                        dp[i][j][k] =  1 + dp[i + 1][j + 1][k + 1];
                    } else {
                        dp[i][j][k] = max({ dp[i][j+1][k], dp[i+1][j][k], dp[i][j][k+1] });
                    }
                }
            }
        }
        
        return dp[0][0][0];
    }
    
    public:
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
        // vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, -1)));
        // return solveRec_Mem(n1, n2, n3, A, B, C, 0, 0, 0, dp);
        
        
        return solve_tab(n1, n2, n3, A, B, C);
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends