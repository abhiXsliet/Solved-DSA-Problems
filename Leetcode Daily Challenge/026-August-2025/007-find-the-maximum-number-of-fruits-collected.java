// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/




import java.util.*;

class Solution {
    private int n;
    private int[][] t;

    public int maxCollectedFruits(int[][] fruits) {
        n = fruits.length;
        t = new int[n + 1][n + 1];

        // return approach_1(fruits);
        return approach_2(fruits);
    }

    private int approach_2(int[][] fruits) {
        int collectChild1 = 0;
        
        // collection of fruits done by child - 1
        for (int i = 0; i < n; i ++) {
            collectChild1 += fruits[i][i];
        }

        // Identify non-restrictive regions where both child-2 and child-3 are allowed to move.
        // In positions where (i + j >= n), neither of them can reach the destination at [n - 1][n - 1].
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i < j) { // only child-2 are allowed to move in this region (upper diagonal)
                    if (i + j >= n - 1) {
                        t[i][j] = fruits[i][j];
                    } 
                } else if (i > j) { // only child-3 are allowed to move in this region (lower diagoanl)
                    if (i + j >= n - 1) {    
                        t[i][j] = fruits[i][j];
                    }
                }
            }
        } 

        // collection of fruits done by child - 2
        for (int i = 1; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                t[i][j] += Math.max( t[i - 1][j - 1], Math.max( t[i - 1][j], ((j + 1 < n) ? t[i - 1][j + 1] : 0) ) );
            }
        }

        // collection of fruits done by child - 3
        for (int j = 1; j < n; j ++) {
            for (int i = j + 1; i < n; i ++) {
                t[i][j] += Math.max( t[i - 1][j - 1], Math.max( t[i][j - 1], ((i + 1 < n) ? t[i + 1][j - 1] : 0) ) );
            }
        }

        return collectChild1 + t[n - 2][n - 1] + t[n - 1][n - 2];
    }  
    
    // TC : O(N^2)
    // SC : O(N^2)
    private int approach_1(int[][] fruits) {
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        
        // collection of fruits done by child - 1
        int result = collectedByChild1(fruits);

        // collection of fruits done by child - 2
        result += collectedByChild2(0, n - 1, fruits);

        // collection of fruits done by child - 3
        result += collectedByChild3(n - 1, 0, fruits);

        return result;
    }

    private int collectedByChild1(int[][] fruits) {
        int collect = 0;
        for (int i = 0; i < n; i ++) {
            collect += fruits[i][i];
        }
        return collect;
    }

    private int collectedByChild2(int i, int j, int[][] fruits) {
        // child-2 can't cross the diagonal (i.e., i < j) since diagonal element is already take by child-1
        if (i >= n || j >= n || j < 0 || i >= j || i == n - 1 && j == n - 1)   
            return 0;
        
        if (t[i][j] != -1) return t[i][j];

        int op1 = fruits[i][j] + collectedByChild2(i + 1, j - 1, fruits);
        int op2 = fruits[i][j] + collectedByChild2(i + 1, j, fruits);
        int op3 = fruits[i][j] + collectedByChild2(i + 1, j + 1, fruits);

        int maxTotal = Math.max(op1, Math.max(op2, op3));
        t[i][j] = maxTotal;
        return maxTotal;
    }

    private int collectedByChild3(int i, int j, int[][] fruits) {
        // child-3 can't cross the diagonal (i.e., i > j) since diagonal element is already take by child-1
        if (i >= n || j >= n || i < 0 || i <= j || i == n - 1 && j == n - 1)   
            return 0;
        
        if (t[i][j] != -1) return t[i][j];

        int op1 = fruits[i][j] + collectedByChild3(i - 1, j + 1, fruits);
        int op2 = fruits[i][j] + collectedByChild3(i, j + 1, fruits);
        int op3 = fruits[i][j] + collectedByChild3(i + 1, j + 1, fruits);

        int maxTotal = Math.max(op1, Math.max(op2, op3));
        t[i][j] = maxTotal;
        return maxTotal;
    }
}