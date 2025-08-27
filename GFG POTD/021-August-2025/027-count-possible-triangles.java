// https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1




import java.util.*;

class Solution {
    public int countTriangles(int arr[]) {
        // return approach_1(arr);
        return approach_2(arr);
    }
    
    // TC : O(N^2)
    // SC : O(1)
    private int approach_2(int[] arr) {
        int n = arr.length;
        
        Arrays.sort(arr);
        int cntTriangles = 0;
        
        for (int k = n - 1; k >= 2; k --) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    cntTriangles += (j - i);
                    j --;
                } else {
                    i ++;
                }
            }
        }
        
        return cntTriangles;
    }
    
    // TC : O(N^3) tle due to simulation
    // SC : O(1)
    private int approach_1(int arr[]) {
        int n = arr.length;
        Arrays.sort(arr);
        
        int i = 0, j = i + 1, k = j + 1, cntTriangles = 0;
        
        while (i < n - 2) {
            while (k < n) {
                if (arr[i] + arr[j] > arr[k]) {
                    cntTriangles += 1;
                }
                k ++;
            }
            
            if (k == n && j < n - 2) {
                j += 1;
                k = j + 1;
            } else if (i < n - 2 && j == n - 2) {
                i += 1;
                j = i + 1;
                k = j + 1;
            } 
        }
        
        return cntTriangles;
    }
}