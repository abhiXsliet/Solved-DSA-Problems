// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/




import java.util.*;

class Solution {
    // TC : O(N*log(N))
    // SC : O(N)
    public long minimumDifference(int[] nums) {
        int n = nums.length;
        int len = n / 3;

        long[] leftMin  = new long[n];
        long[] rightMax = new long[n];
        PriorityQueue<Integer> minH = new PriorityQueue<>();
        PriorityQueue<Integer> maxH = new PriorityQueue<>(Collections.reverseOrder());
        
        long leftMinSum = 0, rightMaxSum = 0;
        for (int i = 0; i < 2*len; i ++) {
            leftMinSum += nums[i];
            maxH.offer(nums[i]);
            if (maxH.size() > len) {
                leftMinSum -= maxH.poll();
            }
            leftMin[i] = leftMinSum;

            rightMaxSum += nums[n - i - 1];
            minH.offer(nums[n - i - 1]);
            if (minH.size() > len) {
                rightMaxSum -= minH.poll();
            }
            rightMax[n - i - 1] = rightMaxSum;
        }

        long result = Long.MAX_VALUE;
        for (int i = len - 1; i < 2*len; i ++) {
            result = Math.min(result, (leftMin[i] - rightMax[i + 1]));
        }
        return result;
    }
}