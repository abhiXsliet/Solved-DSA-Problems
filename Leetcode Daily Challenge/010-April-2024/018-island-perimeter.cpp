// https://leetcode.com/problems/island-perimeter/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // TC : O(M*N) Visit each cell only once
    // SC : O(M*N) Recursive Depth
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        // grid[i][j] = 0 : water so return 1
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) return 1;

        if (grid[i][j] == -1) return 0;
        grid[i][j] = -1;

        int perimeter = 0;
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            perimeter += dfs(grid, new_i, new_j, m, n);
        }
        return perimeter;
    }

    // TC : O(M*N)
    // SC : O(M*N)
    int bfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;

        q.push({i, j});
        grid[i][j]    = -1;
        int perimeter = 0;

        while(!q.empty()) {
            auto it = q.front();    // it.first = i, it.second = j
            q.pop();

            for (auto& dir : directions) {
                int i_ = it.first  + dir[0];
                int j_ = it.second + dir[1];

                if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0) {
                    perimeter ++;
                }
                else if (grid[i_][j_] == -1) {
                    continue;
                }
                else {  // grid[i_][j_] == 1
                    q.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
        }
        return perimeter;
    }

    // TC : O(M*N)
    // SC : O(1)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalPeri = 0;

        for (int i = 0; i < m; i++) {
            for (int j  = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                
                int currPeri = 4;
                if (j + 1 < n && grid[i][j + 1]) currPeri -= 1;
                if (j - 1 >=0 && grid[i][j - 1]) currPeri -= 1;
                if (i - 1 >=0 && grid[i - 1][j]) currPeri -= 1;
                if (i + 1 < m && grid[i + 1][j]) currPeri -= 1;
                
                totalPeri += currPeri;
            }
        }
        return totalPeri;
    }

    // TC : O(M*N)
    // SC : O(1)
    int approach_2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int peri = 0;

        for (int i = 0; i < m; i++) {
            for (int j  = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                
                if (j + 1 >= n || grid[i][j + 1] == 0) peri += 1;
                if (j - 1  < 0 || grid[i][j - 1] == 0) peri += 1;
                if (i - 1  < 0 || grid[i - 1][j] == 0) peri += 1;
                if (i + 1 >= m || grid[i + 1][j] == 0) peri += 1;
            }
        }
        return peri;
    }

    // TC : O(N*M)
    // SC : O(1)
    int approach_3(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j  = 0; j < n; j++) {
                if (grid[i][j] == 1) 
                    return dfs(grid, i, j, m, n);
            }
        }
        return 0;
    }

    // TC : O(N*M)
    // SC : O(N*M)
    int approach_4(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j  = 0; j < n; j++) {
                if (grid[i][j] == 1) 
                    return bfs(grid, i, j, m, n);
            }
        }
        return 0;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // return approach_1(grid);

        return approach_2(grid);

        // return approach_3(grid);

        // return approach_4(grid);
    }
};