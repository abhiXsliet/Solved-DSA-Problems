// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/




class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int maxRow = -1, minRow = m;
        int maxCol = -1, minCol = n;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    maxRow = Math.max(maxRow, i);
                    minRow = Math.min(minRow, i);
                    maxCol = Math.max(maxCol, j);
                    minCol = Math.min(minCol, j);
                }
            }
        } 

        int l = Math.abs(maxRow - minRow) + 1;
        int b = Math.abs(maxCol - minCol) + 1;
        return (l * b);
    }
}