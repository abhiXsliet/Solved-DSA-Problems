// https://leetcode.com/problems/number-of-zero-filled-subarrays/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public long zeroFilledSubarray(int[] nums) {
        int prev = -1;
        long ans = 0;
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] == 0) {
                if (prev == -1) {
                    prev = i;
                    ans += 1;
                } else {
                    ans += (i - prev + 1);
                }
            } else {
                prev = -1;
            }
        }
        return ans;
    }
}