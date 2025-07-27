// https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1



class Solution {
    // TC : O(M * N)
    // SC : O(1)
    public void setMatrixZeroes(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        
        boolean isFirstRow = false, isFirstCol = false;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 && mat[i][j] == 0) isFirstRow = true;
                else if (j == 0 && mat[i][j] == 0) isFirstCol = true;
                else if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == 0 && isFirstRow == true || 
                    j == 0 && isFirstCol == true || 
                    mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                } 
            }
        }
    }
}