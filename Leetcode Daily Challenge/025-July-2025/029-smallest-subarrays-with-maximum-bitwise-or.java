// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;

        int[] result = new int[n];

        // setBitIdx[j] = i, means that jth bit can be set with the element of index i of nums
        int[] setBitIdx = new int[32];
        Arrays.fill(setBitIdx, -1);

        for (int i = n - 1; i >= 0; i --) {

            int endIdx = i;
            for (int j = 0; j < 32; j ++) {
                if ((nums[i] & (1 << j)) == 0) {
                    if (setBitIdx[j] != -1) {
                        endIdx = Math.max(endIdx, setBitIdx[j]);
                    }
                } else {
                    setBitIdx[j] = i;
                }
            }

            result[i] = (endIdx - i + 1);
        }

        return result;
    }
}