// https://leetcode.com/problems/rotting-oranges/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:    
    vector<vector<int>> directions {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    // TC : O(M * N)
    // SC : O(M * N)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 2) 
                    q.push({i, j});
            }
        }

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;
                for (auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ < m && i_ >= 0 && j_ >= 0 && j_ < n && grid[i_][j_] == 1) {
                        grid[i_][j_] = 2;
                        q.push({i_, j_});
                    }
                }
            }
            minutes ++;
        }

        // check if there's still some fresh oranges(i.e, 1)
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes - 1 < 0 ? 0 : minutes - 1;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int freshOranges = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 2) 
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    freshOranges ++;
            }
        }

        if (freshOranges == 0) return 0;   // nothing to make rotten

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;
                for (auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ < m && i_ >= 0 && j_ >= 0 && j_ < n && grid[i_][j_] == 1) {
                        grid[i_][j_] = 2;
                        q.push({i_, j_});
                        freshOranges --;
                    }
                }
            }
            minutes ++;
        }

        return freshOranges == 0 ? minutes - 1 : -1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // return approach_1(grid);     // BFS
        return approach_2(grid);     // BFS : Remove extra for loop in the end
        // DFS is not an ideal solution to this problem : since it doesn't guarantee to visit nodes in shortest time/distance
    }
};