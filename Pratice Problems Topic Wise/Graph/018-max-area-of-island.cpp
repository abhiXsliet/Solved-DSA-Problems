// https://leetcode.com/problems/max-area-of-island/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // TC : O(M*N)  Where M & N are the number of rows and columns
    // SC : O(M*N) -> Recursive Depth
    void dfs(int i, int j, int m, int n, int& area, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        area += 1;

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == 1)
                dfs(i_, j_, m, n, area, grid);
        }
    }

    // TC : O(M*N)  Where M & N are the number of rows and columns
    // SC : O(W)    Where W is the width of the grid
    void bfs(int i, int j, int m, int n, int& area, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        
        while(!q.empty()) {
            area += 1;
            auto it = q.front();
            q.pop();

            for (auto& dir : directions) {
                int i_ = it.first  + dir[0];
                int j_ = it.second + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == 1) {
                    q.push({i_, j_});
                    grid[i_][j_] = 0;
                }
            }
        }
    }

    // TC : O(M*N)  Where M & N are the number of rows and columns
    // SC : O(M*N)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, m, n, area, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    // TC : O(M*N)  Where M & N are the number of rows and columns
    // SC : O(W)    Where W is the width of the grid
    int approach_2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    bfs(i, j, m, n, area, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // return approach_1(grid);

        return approach_2(grid);
    }
};