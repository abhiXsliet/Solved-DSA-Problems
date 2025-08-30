// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1




import java.util.*;

class Solution {
    public int celebrity(int mat[][]) {
        // return approach_1(mat);  // brute
        // return approach_2(mat);  // better : using queue
        return approach_3(mat);     // two pointer, i = 0, j = n - 1
    }
    
    // TC : O(N)
    // SC : O(1)
    private int approach_3(int[][] mat) {
        int n = mat.length;
        
        int i = 0, j = n - 1;
        while (i < j) {
            if (mat[i][j] == 1) {
                i ++;
            } else {
                j --;
            }
        }
        
        // potential celeb = i
        int celeb = i;
        
        // validate celeb
        for (int k = 0; k < n; k ++) {
            if (k != celeb && (mat[celeb][k] == 1 || mat[k][celeb] == 0)) {
                return -1;
            }
        }
        
        return celeb;
    }

    // TC : O(N)
    // SC : O(N)
    private int approach_2(int mat[][]) {
        int n = mat.length;
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i ++) {
            q.offer(i);
        }
        
        int celeb = -1;
        while (q.size() >= 1) {
            if (q.size() == 1) {
                celeb = q.poll();
                break;
            }
            
            int A = q.poll();
            int B = q.poll();
            
            if (mat[A][B] == 1) {
                q.offer(B);
            } else {
                q.offer(A);
            }
        }
        
        // validate celeb
        for (int k = 0; k < n; k ++) {
            if (k != celeb && (mat[celeb][k] == 1 || mat[k][celeb] == 0)) {
                celeb = -1;
                break;
            }
        }
        
        return celeb;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    private int approach_1(int mat[][]) {
        int n = mat.length;
        
        for (int i = 0; i < n; i ++) {
            boolean isCeleb = true;
            for (int j = 0; j < n; j ++) {
                if (i != j && mat[i][j] == 1) {
                    isCeleb = false;
                    break;
                }
            }
            if (isCeleb) {
                for (int j = 0; j < n; j ++) {
                    if (mat[j][i] == 0) {
                        isCeleb = false;
                        break;
                    }
                }
            }
            if (isCeleb) return i;
        }
        
        return -1;
    }
}