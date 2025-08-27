// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/




class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0, zeroCnt = 0, sum = 0, maxi = Integer.MIN_VALUE;
        while (j < n) {
            zeroCnt += (nums[j] == 0) ? 1 : 0;
            sum += nums[j];
            while (zeroCnt > 1) {
                zeroCnt -= (nums[i] == 0) ? 1 : 0;
                sum -= (nums[i]);
                i ++;
            }
            maxi = Math.max(maxi, sum);
            j ++;
        }
        if (n == sum) maxi -= 1;
        return maxi;
    }
}