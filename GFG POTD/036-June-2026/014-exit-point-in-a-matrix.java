// https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1/




import java.util.*;

class Solution {
    public List<Integer> exitPoint(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        
        int dir = 0;    // 0=R, 1=L, 2=D, 3=U
        int i = 0, j = 0;
        
        while (i >= 0 && j >= 0 && i < m && j < n) {
            if (mat[i][j] == 1) {
                dir = (dir + 1) % 4;
                mat[i][j] = 0;
            }
            if (dir == 0) j++;
            else if (dir == 1) i++;
            else if (dir == 2) j--;
            else i--;
        }
        
        if (dir == 0) j--;
        else if (dir == 1) i--;
        else if (dir == 2) j++;
        else i++;
        
        return Arrays.asList(i, j);
    }
}