// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/



class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int maxD = Integer.MIN_VALUE;
        for (int i = 0; i < n; i ++) {
            maxD = Math.max(maxD, Math.abs(nums[i] - nums[(i + 1) % n]));
        }
        return maxD;
    }
}