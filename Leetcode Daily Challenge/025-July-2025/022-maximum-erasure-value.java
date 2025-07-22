// https://leetcode.com/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> mpp = new HashMap<>();
        int i = 0, j = 0, maxSum = 0, sum = 0;
        while (j < n) {
            mpp.put(nums[j], mpp.getOrDefault(nums[j], 0) + 1);
            sum += nums[j];
            while (mpp.getOrDefault(nums[j], 0) > 1) {
                sum -= nums[i];
                mpp.put(nums[i], mpp.getOrDefault(nums[i], 0) - 1);
                if (mpp.getOrDefault(nums[i], 0) == 0) {
                    mpp.remove(nums[i]);
                }
                i ++;
            }
            maxSum = Math.max(maxSum, sum);
            j ++;
        }
        return maxSum;
    }
}