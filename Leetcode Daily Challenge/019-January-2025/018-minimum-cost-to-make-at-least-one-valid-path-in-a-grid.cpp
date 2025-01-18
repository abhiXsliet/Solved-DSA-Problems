// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> dir {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // TC : O(M*N*log(M*N))
    // SC : O(M*N)
    int dijkstras(vector<vector<int>>& grid, int m, int n) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        result[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (result[r][c] < currCost)
                continue; 

            for (int i = 0; i <= 3; i ++) {
                int r_ = r + dir[i][0];
                int c_ = c + dir[i][1];

                if (r_ >= 0 && r_ < m && c_ >= 0 && c_ < n) {
                    int gridCost = grid[r][c];
                    int dirCost  = (gridCost - 1 != i) ? 1 : 0;
                    int newCost  = currCost + dirCost;
                    if (result[r_][c_] > newCost) {
                        result[r_][c_] = newCost;
                        pq.push({newCost, r_, c_});
                    }
                }
            }
        }

        return result[m - 1][n - 1];
    }

    int dfs(int r, int c, vector<vector<int>>& grid, int m, int n, vector<vector<bool>>& vis, int cost) {
        if (r == m - 1 && c == n - 1) 
            return cost;

        vis[r][c] = 1;
        int minCost = INT_MAX;

        for (int i = 0; i <= 3; i ++) {
            int r_ = r + dir[i][0];
            int c_ = c + dir[i][1];

            if (r_ >= 0 && r_ < m && c_ >= 0 && c_ < n && !vis[r_][c_]) {
                int nextCost = cost + ((grid[r][c] - 1 != i) ? 1 : 0);
                minCost = min(minCost, dfs(r_, c_, grid, m, n, vis, nextCost));
            }
        }

        vis[r][c] = 0;
        return minCost;
    }

    // TC : O(3^(M*N))
    // SC : O(M * N)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        return dfs(0, 0, grid, m, n, vis, 0);
    }

    // TC : O(M*N*log(M*N))
    // SC : O(M*N)
    int approach_2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return dijkstras(grid, m, n);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        // return approach_1(grid);    // Try all possible path and return the path with mincost: Backtracking

        return approach_2(grid);
    }
};