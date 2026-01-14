// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/




class Solution {
    // TC : O(N * N/K) ~= O(N)
    // SC : O(N)
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;

        long[] pref = new long[n];
        pref[0] = nums[0];

        for (int i = 1; i < n; i ++) {
            pref[i] += pref[i - 1] + nums[i];
        }

        long result = Long.MIN_VALUE;
        for (int start = 0; start < k; start ++) {  // catch : all the other subarrays are already covered by inner looping

            int i = start;
            long currSubArrSum = 0;

            while (i < n && (i + k - 1) < n) {
                int j = i + k - 1;
                
                long subArrSum = pref[j] - (i - 1 >= 0 ? pref[i - 1] : 0);

                // apply kadanes on the block of size k
                currSubArrSum = Math.max(subArrSum, currSubArrSum + subArrSum);
                result        = Math.max(currSubArrSum, result);
                
                i += k;
            }
        }
        return result;
    }
}