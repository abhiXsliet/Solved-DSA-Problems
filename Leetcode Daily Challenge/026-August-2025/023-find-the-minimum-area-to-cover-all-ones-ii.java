// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/




class Solution {
    public int minimumSum(int[][] grid) {
        int result = util(grid);

        // rotate the grid by 90° CW / CCW
        int[][] rotatedGrid = rotateCW(grid);

        result = Math.min(result, util(rotatedGrid));
        return result;
    }

    private int util(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int result = Integer.MAX_VALUE;

        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                // CASE - 1 
                int topLeft  = minimumArea(0, i, 0, j, grid);
                int topRight = minimumArea(0, i, j, n, grid);
                int bottom   = minimumArea(i, m, 0, n, grid);
                result       = Math.min(result, topLeft + topRight + bottom);

                // CASE - 2
                int top         = minimumArea(0, i, 0, n, grid);
                int bottomLeft  = minimumArea(i, m, 0, j, grid);
                int bottomRight = minimumArea(i, m, j, n, grid);
                result          = Math.min(result, top + bottomLeft + bottomRight);
            }
        }

        // CASE - 3
        for (int c1 = 1; c1 < m; c1 ++) {
            for (int c2 = 1; c2 < m; c2 ++) {
                int top = minimumArea(0, c1, 0, n, grid);
                int mid = minimumArea(c1, c2, 0, n, grid);
                int bot = minimumArea(c2, m, 0, n, grid);
                result  = Math.min(result, top + mid + bot);
            }
        }

        return result;
    }

    private int minimumArea(int stRow, int enRow, int stCol, int enCol, int[][] grid) {
        int m = grid.length, n = grid[0].length;

        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = stRow; i < enRow; i ++) {
            for (int j = stCol; j < enCol; j ++) {
                if (grid[i][j] == 1) {
                    minRow = Math.min(minRow, i);
                    maxRow = Math.max(maxRow, i);
                    minCol = Math.min(minCol, j);
                    maxCol = Math.max(maxCol, j);
                }
            }
        }

        int l = maxRow - minRow + 1;
        int b = maxCol - minCol + 1;

        return (l * b);
    }

    private int[][] rotateCW(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] rotated = new int[n][m];
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                rotated[j][m - i - 1] = grid[i][j];
            }
        }
        return rotated;
    }
}