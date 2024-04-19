// https://leetcode.com/problems/number-of-islands/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    // TC : O(M*N)
    // SC : O(M*N)    
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 ||  i >= m || j < 0 || j >= n || grid[i][j] == '0' || grid[i][j] == '$') return;
        
        grid[i][j] = '$';
        
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            dfs(grid, i_, j_, m, n);
        }
    }

    // TC : O(M*N)
    // SC : O(M*N)    
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});

        grid[i][j] = '$';
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            for (auto& dir : directions) {
                int i_ = it.first  + dir[0];
                int j_ = it.second + dir[1];

                if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == '$' || grid[i_][j_] == '0') {
                    continue;
                }
                else {
                    q.push({i_, j_});
                    grid[i_][j_] = '$';
                }
            }
        }
    }

    // TC : O(M*N)
    // SC : O(M*N)
    int solve_dfs(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cntIsland = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    cntIsland += 1;
                }
            }
        }
        return cntIsland;
    }

    // TC : O(M*N)
    // SC : O(M*N)
    int solve_bfs(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cntIsland = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, m, n);
                    cntIsland += 1;
                }
            }
        }
        return cntIsland;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // return solve_dfs(grid);

        return solve_bfs(grid);
    }
};