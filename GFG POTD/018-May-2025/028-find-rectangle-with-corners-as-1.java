// https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1




import java.util.*;

class Solution {
    public boolean ValidCorner(int mat[][]) {
        // return brute(mat);
        return optimal(mat);
    }
    
    // TC : O(M^2 * N^2)
    // SC : O(1)
    private boolean brute(int mat[][]) {
        int m = mat.length, n = mat[0].length;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 1) {
                    // other (i2, j2) where rectangle might form
                    for (int i2 = i + 1; i2 < m; i2 ++) {
                        for (int j2 = j + 1; j2 < n; j2 ++) {
                            if (mat[i][j2] == 1 && mat[i2][j] == 1 && mat[i2][j2] == 1) {
                                return true;
                            } 
                        }
                    }
                }
            }
        }
        return false;
    }
    
    // TC : O(M * N^2)
    // SC : O(N)
    private boolean optimal(int mat[][]) {
        int m = mat.length, n = mat[0].length;
        Map<Integer, Set<Integer>> mpp = new HashMap<>(); // {j, {from j+1 to n}}
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 1) {
                    for (int j2 = j + 1; j2 < n; j2 ++) {
                        if (mat[i][j2] == 1) {
                            if (mpp.containsKey(j) && mpp.get(j).contains(j2)) {
                                return true;
                            } else {
                                mpp.putIfAbsent(j, new HashSet<>());
                                mpp.get(j).add(j2);
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
}