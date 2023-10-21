// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs_recursive(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, 
                        vector<pair<int, int>>& store, int bRow, int bCol) {
         
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        vis[row][col] = 1;
        store.push_back({row - bRow, col - bCol});
        
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
               && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                
                dfs_recursive(nRow, nCol, grid, vis, store, bRow, bCol);
            }
        }
    }
    
    void dfs_iterative(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, 
                        vector<pair<int, int>>& store, int row0, int col0) {
         
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        stack<pair<int, int>> stk;
        
        vis[row][col] = 1;
        stk.push({row, col});
        store.push_back({row - row0, col - col0});
        
        while(!stk.empty()) {
            int row = stk.top().first;
            int col = stk.top().second;
            stk.pop();
            
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                   && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                    
                    stk.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                    store.push_back({nRow - row0, nCol - col0});
                }
            }
        }
    }
    
    void bfs(int row, int col, vector<vector<int>>& vis, vector<pair<int, int>>& store, 
            vector<vector<int>>& grid, int row0, int col0) {
         
        int n = grid.size();
        int m = grid[0].size();
        
        int dRow[] = {1, 0, -1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        
        q.push({row, col});
        vis[row][col] = 1;
        
        // store the row - baseRow and col - baseCol
        store.push_back({row - row0, col - col0});
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // traverse on the neighbour
            for (int i = 0; i < 4; i++) {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                    && !vis[nRow][nCol] && grid[nRow][nCol] == 1)  {
                    
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                    store.push_back({nRow - row0, nCol - col0});
                }
            }
        }
    }

    // TC = O(N*M)
    // SC = O(N*M)
    int solve_bfs_approach(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> store;
                    bfs(i, j, vis, store, grid, i, j);
                    st.insert(store);
                }
            }
        }
        
        return st.size();
    }
    
    // TC = O(N*M)
    // SC = O(N*M)
    int solve_dfs_iteratively(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> store;
                    dfs_iterative(i, j, grid, vis, store, i, j);
                    st.insert(store);
                }
            }
        }
        
        return st.size();
    }
    
    // TC = O(N*M)
    // SC = O(N*M)
    int solve_dfs_recursively(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> store;
                    dfs_recursive(i, j, grid, vis, store, i, j);
                    st.insert(store);
                }
            }
        }
        
        return st.size();
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        // return solve_bfs_approach(grid);
        
        // return solve_dfs_iteratively(grid);
        
        return solve_dfs_recursively(grid);
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends