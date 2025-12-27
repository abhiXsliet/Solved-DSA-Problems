// https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1/




class Solution {
    // TC : O(N * log(max(mat) - min(mat)))
    // SC : O(1)
    public int kthSmallest(int[][] mat, int k) {
        int n = mat.length;
        int low  = mat[0][0];
        int high = mat[n - 1][n - 1];
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (cntLessThanMid(mat, n, mid) < k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
    private int cntLessThanMid(int[][] mat, int n, int tar) {
        int row = n - 1, col = 0;
        int count = 0;
        while (row >= 0 && col < n) {
            if (mat[row][col] <= tar) {
                count += (row + 1);
                col ++;
            } else {
                row --;
            }
        }
        return count;
    }
}