// https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(K*N*M)
    // SC : O(N*M)
    vector<vector<int>> brute(int k, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp = mat;
        while (k --) {
            for (int i = 0; i < m; i ++) {
                for (int j = 0; j < n; j ++) {
                    mat[j][i] = (i + 1) % m == 0 ? temp[j][0] : mat[j][i + 1];
                }
            }
            temp = mat;
        }
        return mat;
    }
    
    // TC : O(N*M)
    // SC : O(N*M)
    vector<vector<int>> better_1(int k, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp = mat;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                mat[j][i] = temp[j][(i + k) % m];
            }
        }
        
        return mat;
    }
    
    void solve(vector<int>& mat, int k, int m) {
        vector<int> temp = mat;
        for (int j = 0; j < m; j++) {
            mat[j] = temp[(j+k) % m];
        }
    }
    
    // TC : O(N*M)
    // SC : O(M)
    vector<vector<int>> better_2(int k, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for (int i = 0; i < n; i ++) {
            solve(mat[i], k, m);
        }
        
        return mat;
    }
    
    // TC : O(N*M)
    // SC : O(1)
    vector<vector<int>> optimal(int k, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for (vector<int>& row : mat) {
            reverse(begin(row), end(row));
            reverse(rbegin(row), rbegin(row) + (k % m));
            reverse(rbegin(row) + (k % m), rend(row));
        }
        
        return mat;
    }
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // return brute(k, mat);
        
        // return better_1(k, mat);
        
        // return better_2(k, mat);
        
        return optimal(k, mat);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends