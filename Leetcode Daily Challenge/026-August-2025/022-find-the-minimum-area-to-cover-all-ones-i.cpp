// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M * N)
    // SC : O(1)
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxRow = -1, minRow = m;
        int maxCol = -1, minCol = n;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j]) {
                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);
                    maxCol = max(maxCol, j);
                    minCol = min(minCol, j);
                }
            }
        }

        return (abs(maxRow - minRow) + 1) * (abs(maxCol - minCol) + 1);
    }
};