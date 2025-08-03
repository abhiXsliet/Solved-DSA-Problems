// https://www.geeksforgeeks.org/problems/2-d-difference-array/1




import java.util.*;

class Solution {
    // TC : O(M * N)
    // SC : O(M * N)
    public ArrayList<ArrayList<Integer>> applyDiff2D(int[][] mat, int[][] opr) {
        int m = mat.length, n = mat[0].length;
        
        int[][] diffMat = new int[m + 1][n + 1];
        
        for (int[] vec : opr) {
            int val = vec[0];
            int r1 = vec[1], c1 = vec[2], r2 = vec[3], c2 = vec[4];
            
            diffMat[r1][c1]         += val;
            diffMat[r1][c2 + 1]     -= val;
            diffMat[r2 + 1][c1]     -= val;
            diffMat[r2 + 1][c2 + 1] += val;
        }
        
        for (int i = 0; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                diffMat[i][j] += diffMat[i][j - 1];
            }
        }
        
        for (int i = 1; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                diffMat[i][j] += diffMat[i - 1][j];
            }
        }
        
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        for (int i = 0; i < m; i ++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j ++) {
                row.add(mat[i][j] + diffMat[i][j]);
            }
            result.add(row);
        }
        return result;
    }
}