// https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int longestCommonSum(int[] a1, int[] a2) {
        int n = a1.length;
        int sum1 = 0, sum2 = 0, maxLen = 0;
        Map<Integer, Integer> mpp = new HashMap<>();
        mpp.put(0, -1);
        for (int i = 0; i < n; i ++) {
            sum1 += a1[i];
            sum2 += a2[i];
            
            int diff = sum1 - sum2;
            if (mpp.containsKey(diff)) {
                maxLen = Math.max(maxLen, i - mpp.get(diff));
            } else {
                mpp.put(diff, i);
            }
        }
        return maxLen;
    }
}