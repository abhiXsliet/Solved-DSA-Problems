// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/




class Solution {
    public int minimumCost(int[] nums) {
        // return approach_1(nums);
        return approach_2(nums);
    }

    // TC : O(N)
    // SC : O(1)
    private static int approach_2(int[] nums) {
        int n = nums.length;
        int first  = nums[0];
        int second = Integer.MAX_VALUE;
        int third  = Integer.MAX_VALUE;
        for (int i = 1; i < n; i ++) {
            if (nums[i] < second) {
                third = second;
                second = nums[i];
            } else if (nums[i] < third) {
                third = nums[i];
            }
        }
        return first + second + third;
    }

    // TC : O(N^3)
    // SC : O(1)
    private static int approach_1(int[] nums) {
        int n = nums.length;
        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < n - 2; i ++) {
            int sum = nums[0];
            int num2 = Integer.MAX_VALUE;
            for (int j = i + 1; j < n - 1; j ++) {
                num2 = Math.min(num2, nums[j]);
                int num3 = Integer.MAX_VALUE;
                for (int k = j + 1; k < n; k ++) {
                    num3 = Math.min(num3, nums[k]);
                }
                sum += (num2 + num3);
                minSum = Math.min(minSum, sum);
            }
        }
        return minSum;
    }
}