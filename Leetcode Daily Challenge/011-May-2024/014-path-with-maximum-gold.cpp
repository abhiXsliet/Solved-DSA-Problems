// https://leetcode.com/problems/path-with-maximum-gold/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int dfs(vector<vector<int>>& grid, int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;

        int val    = grid[i][j];
        grid[i][j] = 0;
        
        int max_val = 0;
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            max_val = max(max_val, dfs(grid, m, n, i_, j_));
        }
        grid[i][j] = val;
        return max_val + val;
    }
public:
    // TC : O(4^(M + N)) at worst where M & N = No. of rows & cols
    // SC : O(1)
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, dfs(grid, m, n, i, j));
                }
            }
        }
        return ans;
    }
};