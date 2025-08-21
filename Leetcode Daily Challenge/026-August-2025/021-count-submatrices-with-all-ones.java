// https://leetcode.com/problems/count-submatrices-with-all-ones/




import java.util.*;

class Solution {
    public int numSubmat(int[][] mat) {
        return approach_1(mat);
    }

    // TC : O(M * M * N)
    // SC : O(N)
    private int approach_1(int[][] mat) {
        int m = mat.length, n = mat[0].length;

        int cntSubMatrices = 0;

        for (int stRow = 0; stRow < m; stRow ++) {
            int[] compressed = new int[n];
            Arrays.fill(compressed, 1);
            for (int enRow = stRow; enRow < m; enRow ++) {
                for (int j = 0; j < n; j ++) {
                    compressed[j] &= mat[enRow][j];
                }
                cntSubMatrices += getSubMatricesCntOneD(compressed);
            }
        }

        return cntSubMatrices;
    }

    private int getSubMatricesCntOneD(int[] arr) {
        int cntSubMat = 0, consec = 0;
        for (int val : arr) {
            if (val == 0) consec = 0;
            else consec += 1;
            cntSubMat += consec;
        }
        return cntSubMat;
    }
}