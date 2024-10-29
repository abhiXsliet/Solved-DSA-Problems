// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m;
    int n;
    vector<vector<int>> dp;
    vector<vector<int>> directions {{-1, 1}, {0, 1}, {1, 1}};

    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxMove = 0;
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ < m && j_ < n && i_ >= 0 && j_ >= 0 && grid[i_][j_] > grid[i][j]) {
                maxMove = max(maxMove, 1 + solve(grid, i_, j_));
            }
        }
        return dp[i][j] = maxMove;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int mem(vector<vector<int>>& grid) {
        dp = vector<vector<int>> (m + 1, vector<int>(n + 1, -1));

        int maxDist = 0;
        for (int i = 0; i < m; i ++) {
            maxDist = max(maxDist, solve(grid, i, 0));
        }
        return maxDist;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        return mem(grid);
    }
};