// https://www.geeksforgeeks.org/problems/difference-check/1




import java.util.*;

class Solution {
    private final int TOTAL_SEC = 86400;
    
    public int minDifference(String[] arr) {
        // return approach_1(arr);
        return approach_2(arr);
    }
    
    // TC : O(N)
    // SC : O(1)
    private int approach_2(String[] arr) {
        int n = arr.length;
        
        boolean[] timeSeen = new boolean[TOTAL_SEC];
        
        for (int i = 0; i < n; i ++) {
            int seconds = getTotalSeconds(arr[i]);
            if (timeSeen[seconds]) return 0;
            timeSeen[seconds] = true;
        }
        
        int minDiff = Integer.MAX_VALUE, first = -1, prev = -1;
        
        for (int i = 0; i < TOTAL_SEC; i ++) {
            if (timeSeen[i] == true) {
                if (first == -1) first = i;
                if (prev  != -1) minDiff = Math.min(minDiff, i - prev);
                prev = i;
            } 
        }
        
        // wrap around 
        minDiff = Math.min(minDiff, (TOTAL_SEC - (prev - first)));
        
        return minDiff;
    }
    
    // TC : O(N * Log(N))
    // SC : O(N)
    private int approach_1(String[] arr) {
        int n = arr.length;
        
        int[] seconds = new int[n];
        for (int i = 0; i < n; i ++) {
            seconds[i] = getTotalSeconds(arr[i]);
        }
        
        Arrays.sort(seconds);
        
        int minDiff = Integer.MAX_VALUE;
        
        for (int i = 1; i < n; i ++) {
            minDiff = Math.min(minDiff, seconds[i] - seconds[i - 1]);
        }
        
        // Wrap around
        minDiff = Math.min(minDiff, (TOTAL_SEC - (seconds[n - 1] - seconds[0])));
        
        return minDiff;
    }
    
    private int getTotalSeconds (String str) {
        int h = Integer.parseInt(str.substring(0, 2));
        int m = Integer.parseInt(str.substring(3, 5));
        int s = Integer.parseInt(str.substring(6));
        
        return (3600 * h + 60 * m + s);
    }
}