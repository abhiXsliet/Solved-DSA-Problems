// https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1




class Solution {
    // TC : O(log(R) * N*log(N))
    // SC : O(1)
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int low  = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (cntLessThanK(matrix, mid, n) >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    private int cntLessThanK(int[][] matrix, int tar, int n) {
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            cnt += upperBound(matrix[i], tar);
        }
        return cnt;
    }
    private int upperBound(int[] row, int tar) {
        int low = 0, high = row.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] > tar) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}