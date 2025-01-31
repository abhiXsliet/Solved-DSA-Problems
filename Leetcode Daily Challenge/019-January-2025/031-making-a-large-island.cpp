// https://leetcode.com/problems/making-a-large-island/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void depthFirstSearch(vector<vector<int>> &grid, int n, unordered_map<int, int> &mpp, int unique_id, vector<vector<bool>> &vis, int i, int j) {
        vis[i][j] = 1;
        grid[i][j] = unique_id;
        mpp[unique_id] ++;

        for (vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_] == 1 && !vis[i_][j_]) {
                depthFirstSearch(grid, n, mpp, unique_id, vis, i_, j_);
            }
        }
    }

    // TC : O(N^2)
    // SC : O(N^2) due to recursive call stack
    int dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j, int n) {
        int cnt = 1;
        vis[i][j] = 1;
        for (vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && !vis[i_][j_] && grid[i_][j_]) {
                cnt += dfs(grid, vis, i_, j_, n);
            }
        }
        return cnt;
    }

    // TC : O(N^4)
    // SC : O(N^2)
    int approach_1(vector<vector<int>>& grid, int n) {
        int maxArea = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int temp = grid[i][j];
                grid[i][j] = temp == 0 ? 1 : 0;
                vector<vector<bool>> vis(n, vector<bool>(n, 0));
                maxArea = max(maxArea, dfs(grid, vis, i, j, n));
                grid[i][j] = temp == 1 ? 1 : 0;
            }
        }
        return maxArea;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int approach_2(vector<vector<int>>& grid, int n) {
        unordered_map<int, int> mpp;    // stores the size of the island corresponding to their unique id
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        int unique_id = 2;  // since 1, 0 is already used in matrix
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1 && !visited[i][j]) {   // give this island group size an unique id
                    depthFirstSearch(grid, n, mpp, unique_id, visited, i, j);
                    unique_id += 1;
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!grid[i][j]) {
                    unordered_set<int> st;  // store max island component from all four directions
                    for (vector<int>& dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n) {
                            st.insert(grid[i_][j_]);
                        }
                    }

                    int area = 0;
                    for (int it : st) {
                        area += mpp[it];
                    }
                    maxArea = max(maxArea, area + 1);
                }
            }
        }
        return maxArea == 0 ? n*n : maxArea;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        // return approach_1(grid, grid.size());    // Naive

        return approach_2(grid, grid.size());
    }
};