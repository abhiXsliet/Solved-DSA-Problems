// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/




class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;

        int low = 0;
        int high = n - 1;
        int minm = Integer.MAX_VALUE;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[high]) {
                if (nums[low] <= nums[mid]) {
                    minm = Math.min(minm, nums[low]);
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= nums[high]) {
                    minm = Math.min(minm, nums[mid]);
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return minm;
    }
}