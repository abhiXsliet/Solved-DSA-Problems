// https://www.geeksforgeeks.org/problems/assign-mice-holes3053/1/




import java.util.*;

class Solution {
    // TC : O(N * log(N))
    // SC : O(1)
    public int assignHole(int[] mices, int[] holes) {
        Arrays.sort(mices);
        Arrays.sort(holes);
        
        int minTime = Integer.MIN_VALUE;
        for (int i = 0; i < mices.length; i ++) {
            minTime = Math.max(minTime, Math.abs(mices[i] - holes[i]));
        }
        return minTime;
    }
};