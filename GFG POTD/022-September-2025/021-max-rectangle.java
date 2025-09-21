// https://www.geeksforgeeks.org/problems/max-rectangle/1/




import java.util.*;

class Solution {
    private static int m, n;
    
    // TC : O(M * N)
    // SC : O(N)
    static int maxArea(int mat[][]) {
        m = mat.length;
        n = mat[0].length;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i > 0 && mat[i][j] != 0) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }
        
        int maxArea = 0;
        for (int[] row : mat) {
            maxArea = Math.max(maxArea, getMaxAreaRow(row));
        }
        return maxArea;
    }
    
    // TC : O(N)
    // SC : O(N)
    private static int getMaxAreaRow(int[] row) {
        int[] nse = getNse(row);
        int[] pse = getPse(row);
        
        int maxArea = 0;
        for (int i = 0; i < n; i ++) {
            int len = (nse[i] - pse[i] - 1);
            int wdt = row[i];
            maxArea = Math.max(maxArea, (len * wdt));
        }
        return maxArea;
    }
    
    // TC : O(N)
    // SC : O(N)
    private static int[] getNse(int[] arr) {
        int[] result = new int[n];
        for (int i = 0; i < n; i ++) {
            result[i] = n;
        }
        
        Stack<Integer> stk = new Stack<>();
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.isEmpty() && arr[stk.peek()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) result[i] = stk.peek();
            stk.push(i);
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    private static int[] getPse(int[] arr) {
        int[] result = new int[n];
        for (int i = 0; i < n; i ++) {
            result[i] = -1;
        }
        
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < n; i ++) {
            while (!stk.isEmpty() && arr[stk.peek()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) result[i] = stk.peek();
            stk.push(i);
        }
        return result;
    }
}