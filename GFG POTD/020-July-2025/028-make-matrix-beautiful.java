// https://www.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1




class Solution {
    // TC : O(M * N)
    // SC : O(1)
    public static int balanceSums(int[][] mat) {
        int m = mat.length;
        int maxSum = 0;
        for (int i = 0; i < m; i ++) {
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < m; j ++) {
                sum1 += mat[i][j];
                sum2 += mat[j][i];
            }
            maxSum = Math.max(maxSum, Math.max(sum1, sum2));
        }
        
        int minOpr = 0;
        for (int i = 0; i < m; i ++) {
            int sum = 0;
            for (int j = 0; j < m; j ++) {
                sum += mat[i][j];
            }
            minOpr += Math.abs(maxSum - sum);
        }
        return minOpr;
    }
}