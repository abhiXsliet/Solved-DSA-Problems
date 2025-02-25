// https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    // TC : O(M * N)
    // SC : O(M * N) depth of recursive call stack
    int dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int nextExpectedVal, int dir, bool canMakeTurn) {
        int i_ = i + directions[dir][0];
        int j_ = j + directions[dir][1];
        
        if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != nextExpectedVal)
            return 0;
            
        // continuing in the same direction without any 90 turn
        int result = 1 + dfs(grid, m, n, i_, j_, 2 - nextExpectedVal, dir, canMakeTurn);        // no turn

        // changing the direction with 90 turn
        if (!canMakeTurn) {
            int nextDir = (dir + 1) % 4;
            result = max(result, 1 + dfs(grid, m, n, i_, j_, 2 - nextExpectedVal, nextDir, 1));     // turn
        }
        return result;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int maxLenSegment = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir ++) {
                        maxLenSegment = max(maxLenSegment, 1 + dfs(grid, m, n, i, j, 2, dir, 0));  // sequence required to dfs : 2, 0, 2, 0, ...
                    }
                }
            }
        }
        return maxLenSegment;
    }
};