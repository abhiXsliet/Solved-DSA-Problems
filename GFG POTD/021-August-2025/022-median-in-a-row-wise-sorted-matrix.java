// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1




class Solution {
    // TC : O(log(maxi - mini) * n*log(m))
    // SC : O(1)
    public int median(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int low = Integer.MAX_VALUE, high = Integer.MIN_VALUE;
        
        for (int i = 0; i < n; i ++) {
            low  = Math.min(low , mat[i][0]);
            high = Math.max(high, mat[i][m - 1]);
        }
        
        int medianPos = ((n * m) / 2) + 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int pos = getMidPos(mat, mid);
            if (pos >= medianPos) {
                result = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return result;
    }
    // TC : O(N * log(M))
    private int getMidPos(int[][] mat, int tar) {
        int cntPos = 0;
        for (int[] row : mat) {
            cntPos += upperBound(row, tar);
        }
        return cntPos;
    }
    // TC : O(log(M))
    private int upperBound(int[] mat, int tar) {
        int low = 0, high = mat.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mat[mid] > tar) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}