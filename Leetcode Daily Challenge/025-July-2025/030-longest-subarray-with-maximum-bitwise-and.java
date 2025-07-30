// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int longestSubarray(int[] nums) {
        int maxi = 0, maxLen = 0, seqLen  = 0;
        for (int num : nums) {
            if (num > maxi) {
                maxi = num;
                seqLen = 0;
                maxLen = 0;
            }

            seqLen = (num == maxi) ? seqLen + 1 : 0;
            
            maxLen = Math.max(maxLen, seqLen);
        }
        return maxLen;
    }
}