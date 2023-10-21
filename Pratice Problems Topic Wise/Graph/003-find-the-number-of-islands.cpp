// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // Depth-First Search (DFS) with implicit stack
    // TC = O( N*M ), SC = O( N*M )
    void dfs_recursive(int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // all possible 8-directions for traversal
        int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        // mark cell as visited
        vis[row][col] = 1;
        
        // traverse on the directions
        for (int i = 0; i < 8; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                && !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                
                dfs_recursive(newRow, newCol, vis, grid);     
            }
        }
    }
    
    // Depth-First Search (DFS) with explicit stack
    // TC = O( N*M ), SC = O( N*M )
    void dfs_iterative(int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        stack<pair<int, int>> stk;
        stk.push({row, col});
        vis[row][col] = 1;
            
        while(!stk.empty()) {
            int row  = stk.top().first;
            int col  = stk.top().second;
            stk.pop();
            
            // traverse on their respective neighbour and mark them
            for (int delRow = -1; delRow <= 1; delRow++) {
                for (int delCol = -1; delCol <= 1; delCol++) {
                    
                    int newRow = row + delRow;
                    int newCol = col + delCol;
                    
                    if (newRow < n && newRow >= 0 && newCol < m && newCol >= 0
                        && !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                        
                        vis[newRow][newCol] = 1;
                        stk.push({newRow, newCol});
                    }
                }
            }
        }
    }

    // Breadth-First Search (BFS) approach
    // TC = O( N*M ), SC = O( N*M )
    void bfs(int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // // all possible 8-directions for traversal
        // int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        // int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        queue<pair<int, int>> que;
        que.push({row, col});
        vis[row][col] = 1;
            
        while(!que.empty()) {
            int row  = que.front().first;
            int col  = que.front().second;
            que.pop();
            
            // traverse on their respective neighbour and mark them
            for (int delRow = -1; delRow <= 1; delRow++) {
                for (int delCol = -1; delCol <= 1; delCol++) {
                    
                    int newRow = row + delRow;
                    int newCol = col + delCol;
                    
                    if (newRow < n && newRow >= 0 && newCol < m && newCol >= 0
                        && !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                        
                        vis[newRow][newCol] = 1;
                        que.push({newRow, newCol});
                    }
                }
            }
        }
    }
    
    int solve_bfs(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        
        return cnt;
    }
    
    int solve_dfs_iteratively(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs_iterative(i, j, vis, grid);
                }
            }
        }
        
        return cnt;
    }
    
    int solve_dfs_recursively(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs_recursive(i, j, vis, grid);
                }
            }
        }
        
        return cnt;
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        // return solve_bfs(grid);
        
        // return solve_dfs_iteratively(grid);
        
        return solve_dfs_recursively(grid);
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