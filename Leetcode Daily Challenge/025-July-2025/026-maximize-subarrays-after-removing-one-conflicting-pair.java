// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public long maxSubarrays(int n, int[][] conflictingPairs) {
        List<List<Integer>> conflictPoints = new ArrayList<>();
        for (int i = 0; i <= n; i ++) {
            conflictPoints.add(new ArrayList<>());
        }

        for (int[] pair : conflictingPairs) {
            if (pair[0] > pair[1]) conflictPoints.get(pair[0]).add(pair[1]);
            else conflictPoints.get(pair[1]).add(pair[0]);
        }

        long[] extraPoints = new long[n + 1];
        // extra[i] = no. of extra subarray after removing conflictingPair i

        long totalValidSubarray = 0, firstMaxConflict = 0, secondMaxConflict = 0;

        for (int i = 1; i <= n; i ++) { // total valid subarrays at index i

            for (int val : conflictPoints.get(i)) {
                if (val >= firstMaxConflict) {
                    secondMaxConflict = firstMaxConflict;
                    firstMaxConflict  = val;
                } else if (val > secondMaxConflict) {
                    secondMaxConflict = val;
                }
            }

            totalValidSubarray += (i - firstMaxConflict);
            extraPoints[(int)firstMaxConflict] += (firstMaxConflict - secondMaxConflict); 
        }

        long extraSubarray = Arrays.stream(extraPoints).max().getAsLong();
        return (totalValidSubarray + extraSubarray);
    }
}