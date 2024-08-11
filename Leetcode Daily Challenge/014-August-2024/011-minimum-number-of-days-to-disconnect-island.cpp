// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Directions for exploring the neighboring cells in the grid
    vector<int> directions {-1, 0, 1, 0, -1};
    int m, n;

    // Depth-first search to explore an island
    void DFS(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 2 || grid[i][j] == 0)
            return;

        // Mark the current cell as visited
        grid[i][j] = 2; 

        for (int k = 0; k < 4; ++k) {

            int i_ = i + directions[k];
            int j_ = j + directions[k + 1];
            
            DFS(i_, j_, grid);
        }
    }

    // Function that counts the number of islands in the grid
    int countIslands(vector<vector<int>>& grid) {
        int cntIslands = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 1) {
                    DFS(i, j, grid);
                    cntIslands ++;
                }
            }
        }

        // Reset the grid to its original state
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }

        return cntIslands;
    }

    // TC : O((N*M)^2)
    // SC : O(1)
    int solve_approach_1(vector<vector<int>>& grid) {
        // If the grid is already disconnected, return 0 as req days to disconnect
        if (countIslands(grid) != 1) 
            return 0;

        // Try removing each island and check if the grid becomes disconnected
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 1) {

                    grid[i][j] = 0;

                    if (countIslands(grid) != 1) {  // we are able to disconnect island in 1-day only
                        return 1;
                    }
                    
                    grid[i][j] = 1;
                }
            }
        }

        // If removing any single island doesn't disconnect the grid, then removing any two islands definitely will
        return 2;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        return solve_approach_1(grid);
    }
};