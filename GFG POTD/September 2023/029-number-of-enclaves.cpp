// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool isSafe(int x,int y, vector<vector<bool>>&vis,int n, int m,vector<vector<int>>&grid) {
        return (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1 and vis[x][y] == 0);
    }
    void dfs(int i,int j,vector<vector<bool>>&vis,int n, int m,vector<vector<int>>&grid) {
        vis[i][j] = 1;
        for(int k=0;k<4;k++) {
            int x = i + dx[k] ;
            int y = j + dy[k];
            if(isSafe(x,y,vis,n,m,grid)) {
               dfs(x,y,vis,n,m,grid);
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
 
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1) {
                dfs(i,0,vis,n,m,grid);
            }
            if (grid[i][m-1] == 1) {
                dfs(i,m-1,vis,n,m,grid);
            }
        }
 
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1) {
                dfs(0,j,vis,n,m,grid);
            }
            if (grid[n-1][j] == 1) {
                dfs(n-1,j,vis,n,m,grid);
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1 and vis[i][j] == 0) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends