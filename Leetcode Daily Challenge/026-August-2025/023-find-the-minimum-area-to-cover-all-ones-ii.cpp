// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int minimumArea(int stRow, int enRow, int stCol, int enCol, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = stRow; i < enRow; i ++) {
            for (int j = stCol; j < enCol; j ++) {
                if (grid[i][j]) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        int l = maxRow - minRow + 1;
        int b = maxCol - minCol + 1;

        return (l * b);
    }

    vector<vector<int>> rotatedCW(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rotated(n, vector<int>(m, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                rotated[j][m - i - 1] = grid[i][j];
            }
        }
        return rotated;
    }

    int util(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int result = INT_MAX;

        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {

                //             _________
                // case - 1 : |    |    |
                //            |____|____|
                //            |_________|
                int topLeft  = minimumArea(0, i, 0, j, grid);
                int topRight = minimumArea(0, i, j, n, grid);
                int bottom   = minimumArea(i, m, 0, n, grid);
                result       = min(result, topLeft + topRight + bottom);

                //             _________
                // case - 2 : |_________|
                //            |    |    |
                //            |____|____|
                int top         = minimumArea(0, i, 0, n, grid);
                int bottomLeft  = minimumArea(i, m, 0, j, grid);
                int bottomRight = minimumArea(i, m, j, n, grid);
                result          = min(result, top + bottomLeft + bottomRight);
            }
        }

        //             _________
        // case - 3 : |_________|
        //            |_________|
        //            |_________|
        for (int c1 = 1; c1 < m; c1 ++) {
            for (int c2 = 1; c2 < m; c2 ++) {
                int top = minimumArea(0, c1, 0, n, grid);
                int mid = minimumArea(c1, c2, 0, n, grid);
                int bot = minimumArea(c2, m, 0, n, grid);
                result  = min(result, top + mid + bot);
            }
        }

        return result;
    }
public:
    // TC : O(M^2 * N^2)
    // SC : O(M * N)
    int minimumSum(vector<vector<int>>& grid) {
        int result = util(grid);

        // rotate the grid by 90° (CW/CCW) to cover the rest remaining three cases
        vector<vector<int>> rotatedGrid = rotatedCW(grid);

        result = min(result, util(rotatedGrid));
        return result;
    }
};