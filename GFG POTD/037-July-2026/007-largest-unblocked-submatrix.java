// https://www.geeksforgeeks.org/problems/largest-unblocked-submatrix/1




import java.util.*;

class Solution {
    // TC : O(KlogK) Where K = size of arr
    // SC : O(K)
    public int largestArea(int n, int m, int[][] arr) {
        Set<Integer> stRows = new HashSet<>();
        Set<Integer> stCols = new HashSet<>();
        
        for (int[] a : arr) {
            if (!stRows.contains(a[0] - 1)) {
                stRows.add(a[0] - 1);
            }
            if (!stCols.contains(a[1] - 1)) {
                stCols.add(a[1] - 1);
            }
        }
        
        int maxRowContinuousCnt = 0, maxColContinuousCnt = 0;
        int rowCnt = 0, colCnt = 0;
        
        for (int i = 0; i < n; i ++) {
            if (stRows.contains(i)) {
                maxRowContinuousCnt = Math.max(maxRowContinuousCnt, rowCnt);
                rowCnt = 0;
            } else {
                rowCnt += 1;
            }
        }

        for (int i = 0; i < m; i ++) {
            if (stCols.contains(i)) {
                maxColContinuousCnt = Math.max(maxColContinuousCnt, colCnt);
                colCnt = 0;
            } else {
                colCnt += 1;
            }
        }

        maxRowContinuousCnt = Math.max(maxRowContinuousCnt, rowCnt);
        maxColContinuousCnt = Math.max(maxColContinuousCnt, colCnt);

        return maxRowContinuousCnt * maxColContinuousCnt;
    }
}