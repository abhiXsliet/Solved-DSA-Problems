// https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N * M)
    // SC : O(N * M)
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        // Step 1: Push all 1s into queue as BFS sources
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // 4 directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // Step 2: Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                
                // Check boundaries + unvisited
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return dist;
    }
};