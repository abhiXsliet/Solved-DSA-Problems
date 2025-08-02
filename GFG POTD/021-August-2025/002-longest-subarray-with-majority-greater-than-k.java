// https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int longestSubarray(int[] arr, int k) {
        int n = arr.length;
        Map<Integer, Integer> mpp = new HashMap<>();
        int maxLen = 0, sum = 0;
        
        for (int i = 0; i < n; i ++) {
            sum += (arr[i] > k) ? 1 : -1;
           
            if (sum > 0) {
                maxLen = Math.max(maxLen, i + 1);
            } else {
                if (mpp.containsKey(sum - 1)) {
                    maxLen = Math.max(maxLen, i - mpp.get(sum - 1));
                }
            }
            
            if (!mpp.containsKey(sum)) {
                mpp.put(sum, i);
            }
        }
        return maxLen;
    }
}