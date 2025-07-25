// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/




import java.util.*;

class Solution {
    public int maxSum(int[] nums) {
        return approach_1(nums);
        // return approach_2(nums);    // using ArrayList of constant length
    }

    // TC : O(N)
    // SC : O(1)
    private int approach_2(int[] nums) {
        int[] freq  = new int[101];
        Arrays.fill(freq, -1);
        int negMaxi = Integer.MIN_VALUE;
        int maxSum  = 0;

        for (int num : nums) {
            if (num > 0) {
                if (freq[num] == -1) {
                    maxSum += num;
                    freq[num] = 1;
                }
            } else {
                negMaxi = Math.max(negMaxi, num);
            }
        }

        return maxSum == 0 ? negMaxi : maxSum;
    }

    // TC : O(N)
    // SC : O(N)
    private int approach_1(int[] nums) {
        int maxSum = 0;
        int negMaxi = Integer.MIN_VALUE;
        boolean hasPositive = false;
        Set<Integer> st = new HashSet<>();

        for (int num : nums) {
            if (num >= 0 && !st.contains(num)) {
                st.add(num);
                hasPositive = true;
                maxSum += num;
            } else {
                negMaxi = Math.max(negMaxi, num);
            }
        }

        if (!hasPositive) return negMaxi;

        return maxSum;
    }
}