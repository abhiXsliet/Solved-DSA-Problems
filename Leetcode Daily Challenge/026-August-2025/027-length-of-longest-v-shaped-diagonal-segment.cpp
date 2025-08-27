// https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int t[501][501][4][2];

    // TC : O(M * N)
    // SC : O(M * N)
    int solve(vector<vector<int>>& grid, int i, int j, int d, bool canTurn, int nextCellVal) {
        int i_ = i + directions[d][0];
        int j_ = j + directions[d][1];

        if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != nextCellVal)
            return 0;

        if (t[i_][j_][d][canTurn] != -1) 
            return t[i_][j_][d][canTurn];

        int noTurnDist = 1 + solve(grid, i_, j_, d, canTurn, nextCellVal == 2 ? 0 : 2);

        if (canTurn) {
            int turnedDist = 1 + solve(grid, i_, j_, (d + 1) % 4, false, nextCellVal == 2 ? 0 : 2);
            noTurnDist     = max(noTurnDist, turnedDist);
        }

        return t[i_][j_][d][canTurn] = noTurnDist;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        memset(t, -1, sizeof(t));
        
        int result = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d ++) {
                        result = max(result, 1 + solve(grid, i, j, d, true, 2));
                    }
                }
            }
        }
        return result;
    }
};