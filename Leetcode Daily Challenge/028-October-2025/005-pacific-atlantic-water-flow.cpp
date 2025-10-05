// https://leetcode.com/problems/pacific-atlantic-water-flow/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int m, n;

    bool inBound(int i, int j) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>> &q, vector<vector<bool>>& vis) {
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            vis[i][j] = true;
            for (auto &dir : directions) {
                int i_ = i + dir[0], j_ = j + dir[1];
                if (inBound(i_, j_) && !vis[i_][j_] && heights[i_][j_] >= heights[i][j]) {
                    q.push({i_, j_});
                }
            } 
        }
    }

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (inBound(i_, j_) && !vis[i_][j_] && heights[i_][j_] >= heights[i][j])
                dfs(heights, i_, j_, vis);
        }
    }

    // is possible to reach to Pacific or Atlantic ocean (0 : pacific, 1 : atlantic)
    bool canReach(int i, int j, vector<vector<int>>& heights, vector<vector<bool>> &vis, bool ocean) {
        if ((!ocean && (i == 0 || j == 0)) || (ocean && (i == m - 1 || j == n - 1)))
            return true;

        vis[i][j] = 1;

        for (auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (inBound(i_, j_) && !vis[i_][j_] && heights[i_][j_] <= heights[i][j]) {
                if (canReach(i_, j_, heights, vis, ocean))
                    return true;
            }
        }

        return false;
    }
    
    // TC : O((N*M)^2)
    // SC : O(N*M)
    vector<vector<int>> brute(vector<vector<int>>& heights) {
        vector<vector<int>> result;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                vector<vector<bool>> vis1(m, vector<bool>(n, 0)), vis2(m, vector<bool>(n, 0));
                if (canReach(i, j, heights, vis1, 0) && canReach(i, j, heights, vis2, 1)) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    // TC : O(M*N)
    // SC : O(M*N)
    vector<vector<int>> optimal_1(vector<vector<int>>& heights) {
        vector<vector<bool>> isPacific (m, vector<bool>(n, 0)), isAtlantic(m, vector<bool>(n, 0));

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                // mark all cells reachable from pacific
                if ((i == 0) || (j == 0))
                    dfs(heights, i, j, isPacific);

                // mark all cells reachable from atlantic
                if ((i == m - 1) || (j == n - 1))
                    dfs(heights, i, j, isAtlantic);
            }
        }

        vector<vector<int>> result;

        // take the common reachable cells from both atlantic and pacific
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (isPacific[i][j] && isAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    // TC : O(M*N)
    // SC : O(M*N)
    vector<vector<int>> optimal_2(vector<vector<int>>& heights) {
        vector<vector<bool>> isPacific (m, vector<bool>(n, 0)), isAtlantic(m, vector<bool>(n, 0));
        queue<pair<int, int>> pac, atl;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                // mark all cells reachable from pacific
                if ((i == 0) || (j == 0))
                    pac.push({i, j});

                // mark all cells reachable from atlantic
                if ((i == m - 1) || (j == n - 1))
                    atl.push({i, j});
            }
        }

        bfs(heights, pac, isPacific);
        bfs(heights, atl, isAtlantic);

        vector<vector<int>> result;

        // take the common reachable cells from both atlantic and pacific
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (isPacific[i][j] && isAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();

        // return brute(heights);
        // return optimal_1(heights);    // dfs 
        return optimal_2(heights);    // bfs 
    }
};