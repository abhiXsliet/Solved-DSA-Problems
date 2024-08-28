// https://leetcode.com/problems/count-sub-islands/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool BFS(int i, int j, int m, int n, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid2[i][j] = 0;

        bool subIsland = true;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            if (!grid1[it.first][it.second]) 
                subIsland = false;

            for (auto& dir : directions) {
                int i_ = it.first  + dir[0];
                int j_ = it.second + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid2[i_][j_]) {
                    grid2[i_][j_] = 0;
                    q.push({i_, j_});
                }
            }
        }
        return subIsland;
    }

    bool DFS(int i, int j, int m, int n, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0)
            return true;

        if (grid1[i][j] == 0) 
            return false;

        grid2[i][j] = 0;   // mark visited

        bool subIsland = true;
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (!DFS(i_, j_, m, n, grid1, grid2)) {
                subIsland = false;
            }
        }
        return subIsland;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_1(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();

        int subIsland = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                // DFS checks if the grid1 contains subIsland by checking cells of islands of grid2
                if (grid2[i][j] && DFS(i, j, m, n, grid1, grid2)) { 
                    subIsland += 1;
                }
            }
        }
        return subIsland;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();

        int subIsland = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                // DFS checks if the grid1 contains subIsland by checking cells of islands of grid2
                if (grid2[i][j] && BFS(i, j, m, n, grid1, grid2)) { 
                    subIsland += 1;
                }
            }
        }
        return subIsland;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // return approach_1(grid1, grid2);

        return approach_2(grid1, grid2);
    }
};