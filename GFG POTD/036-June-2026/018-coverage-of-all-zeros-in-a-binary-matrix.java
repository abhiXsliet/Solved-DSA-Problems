// https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1/




class Solution {
    public int findCoverage(int[][] mat) {

        int m = mat.length;
        int n = mat[0].length;

        int totalCoverage = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] != 0)
                    continue;

                // UP
                for (int r = i - 1; r >= 0; r--) {
                    if (mat[r][j] == 1) {
                        totalCoverage++;
                        break;
                    }
                }

                // DOWN
                for (int r = i + 1; r < m; r++) {
                    if (mat[r][j] == 1) {
                        totalCoverage++;
                        break;
                    }
                }

                // LEFT
                for (int c = j - 1; c >= 0; c--) {
                    if (mat[i][c] == 1) {
                        totalCoverage++;
                        break;
                    }
                }

                // RIGHT
                for (int c = j + 1; c < n; c++) {
                    if (mat[i][c] == 1) {
                        totalCoverage++;
                        break;
                    }
                }
            }
        }

        return totalCoverage;
    }
}