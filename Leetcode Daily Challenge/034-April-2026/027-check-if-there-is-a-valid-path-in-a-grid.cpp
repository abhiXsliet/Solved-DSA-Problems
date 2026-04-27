// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n;

    unordered_map<int, vector<vector<int>>> mpp {
        {1, {{0, -1}, {0,  1}}}, 
        {2, {{-1, 0}, {1,  0}}}, 
        {3, {{0, -1}, {1,  0}}}, 
        {4, {{0,  1}, {1,  0}}}, 
        {5, {{-1, 0}, {0, -1}}}, 
        {6, {{-1, 0}, {0,  1}}} 
    };

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j) {
        if (i == m - 1 && j == n - 1) return true;

        visited[i][j] = true;

        for (auto &dir : mpp[grid[i][j]]) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                
                for (auto &backDir : mpp[grid[new_i][new_j]]) {
                    
                    if (new_i + backDir[0] == i && new_j + backDir[1] == j) {
                       
                        if (dfs(grid, visited, new_i, new_j))
                            return true;
                    }

                }
                
            }
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        return dfs(grid, visited, 0, 0);
    }
};