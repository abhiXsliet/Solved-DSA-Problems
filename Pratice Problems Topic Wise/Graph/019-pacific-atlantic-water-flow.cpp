// https://leetcode.com/problems/pacific-atlantic-water-flow/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(vector<vector<int>>& heights, int i, int j, int m, int n, 
             int prev, vector<vector<bool>>& grid) {

        if (i < 0 || i >= m || j < 0 || j >= n || heights[i][j] < prev || grid[i][j]) return;

        grid[i][j] = 1;

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            dfs(heights, i_, j_, m, n, heights[i][j], grid);
        }
    }

    bool isPossible(int i, int j, int m, int n, vector<vector<int>>& heights, bool isPacific) {
        if (isPacific ? (i == 0 || j == 0) : (i == m - 1) || (j == n - 1))
            return true;
        if (heights[i][j] == -1) 
            return false;

        int val = heights[i][j];
        heights[i][j] = -1;

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && heights[i_][j_] <= val &&
                isPossible(i_, j_, m, n, heights, isPacific)) {
                
                heights[i][j] = val;
                return true;
            }
        }

        heights[i][j] = val;
        return false;
    }

    // is possible to reach to Pacific grid ?
    bool reachPacific(int i, int j, int m, int n, vector<vector<int>>& heights) {
        if (i == 0 || j == 0)   // top - left is pacific
            return 1;
        if (heights[i][j] == -1) 
            return 0;

        int val = heights[i][j];
        heights[i][j] = -1;
        bool flag     =  0;

        // Make Call in 4-directions
        if (heights[i - 1][j] <= val) {
            flag = reachPacific(i - 1, j, m, n, heights);
        }
        if (!flag && heights[i][j-1] <= val) {
            flag = reachPacific(i, j - 1, m, n, heights);
        }
        if (!flag && i + 1 < m && heights[i + 1][j] <= val) {
            flag = reachPacific(i + 1, j, m, n, heights);
        }
        if (!flag && j + 1 < n && heights[i][j + 1] <= val) {
            flag = reachPacific(i, j + 1, m, n, heights);
        }
        heights[i][j] = val;
        return flag;
    }

    // is possible to reach to Atlantic grid ?
    bool reachAtlantic(int i, int j, int m, int n, vector<vector<int>>& heights) {
        if (i == m - 1 || j == n - 1)   // bottom right is atlantic
            return 1;
        if (heights[i][j] == -1)
            return 0;
        
        int val = heights[i][j];
        heights[i][j] = -1;
        bool flag = 0;

        // Make Calls in 4-Directions
        if (heights[i + 1][j] <= val) {
            flag = reachAtlantic(i + 1, j, m, n, heights);
        }
        if (!flag && heights[i][j + 1] <= val) {
            flag = reachAtlantic(i, j + 1, m, n, heights);
        }
        if (!flag && i - 1 >= 0 && heights[i - 1][j] <= val) {
            flag = reachAtlantic(i - 1, j, m, n, heights);
        }
        if (!flag && j - 1 >= 0 && heights[i][j - 1] <= val) {
            flag = reachAtlantic(i, j - 1, m, n, heights);
        }

        heights[i][j] = val;
        return flag;
    }
    
    // TC : O(N*M (N + M))
    // SC : O(1)
    vector<vector<int>> solve_brute(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (reachPacific(i, j, m, n, heights) && reachAtlantic(i, j, m, n, heights)) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    // TC : O(N*M (N + M))
    // SC : O(1)
    vector<vector<int>> solve_brute_modified(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (isPossible(i, j, m, n, heights, 1) && isPossible(i, j, m, n, heights, 0)) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    // TC : O(M*N)
    // SC : O(M*N)
    vector<vector<int>> solve_optimal(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> isPacific (m, vector<bool>(n, 0));
        vector<vector<bool>> isAtlantic(m, vector<bool>(n, 0));

        // DFS
        for (int r = 0; r < m; r ++) {
            dfs(heights, r, 0, m, n, INT_MIN, isPacific);
            dfs(heights, r, n - 1, m, n, INT_MIN, isAtlantic);
        }
        for (int c = 0; c < n; c ++) {
            dfs(heights, 0, c, m, n, INT_MIN, isPacific);
            dfs(heights, m - 1, c, m, n, INT_MIN, isAtlantic);
        }

        vector<vector<int>> result;
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
        // return solve_brute(heights);

        // return solve_brute_modified(heights);

        return solve_optimal(heights);  // DFS

                                        // Pending BFS?
    }
};