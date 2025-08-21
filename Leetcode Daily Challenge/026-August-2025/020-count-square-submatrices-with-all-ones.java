// https://leetcode.com/problems/count-square-submatrices-with-all-ones/




class Solution {
    // TC : O(N * N)
    // SC : O(1)
    public int countSquares(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int cntSquareSubMatrices = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i > 0 && j > 0 && matrix[i][j] == 1) {
                    matrix[i][j] += Math.min(matrix[i - 1][j - 1], Math.min(matrix[i - 1][j], matrix[i][j - 1]));
                }
                cntSquareSubMatrices += matrix[i][j];
            }
        }
        return cntSquareSubMatrices;
    }
}