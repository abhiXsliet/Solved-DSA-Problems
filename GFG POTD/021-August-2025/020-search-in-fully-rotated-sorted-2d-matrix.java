// https://www.geeksforgeeks.org/problems/search-in-fully-rotated-sorted-2d-matrix/1




class Solution {
    // TC : O(log(N * M))
    // SC : O(1)
    public boolean searchMatrix(int[][] mat, int x) {
        int n = mat.length, m = mat[0].length;
        
        int low = 0, high = n * m - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;
            
            if (mat[row][col] == x) return true;
            
            int lRow = low  / m, lCol = low  % m;
            int hRow = high / m, hCol = high % m;
            
            if (mat[lRow][lCol] <= mat[row][col]) { // left part is sorted
                if (x >= mat[lRow][lCol] && x < mat[row][col]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (x > mat[row][col] && x <= mat[hRow][hCol]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
}