// https://leetcode.com/problems/transformed-array/




class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        for (int i = 0; i < n; i ++) {
            int val = nums[i];
            if (nums[i] > 0) val = nums[(i + nums[i]) % n];
            else if (nums[i] < 0) val = nums[(i - Math.abs(nums[i]) % n + n) % n];
            result[i] = val;
        }
        return result;
    }
}