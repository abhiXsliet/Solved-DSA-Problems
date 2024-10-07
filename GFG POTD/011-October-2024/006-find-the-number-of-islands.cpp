// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    vector<vector<int>> directions {{-1, -1}, {-1, 0}, {-1, 1}, {0,  1}, 
                                    { 1,  1}, { 1, 0}, {1, -1}, {0, -1}};
    
    int n;
    int m;
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] != '1') 
            return;
            
        grid[i][j] = '#';
        
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            dfs(i_, j_, grid);
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islandsCnt = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    islandsCnt ++;
                }
            }
        }
        return islandsCnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends