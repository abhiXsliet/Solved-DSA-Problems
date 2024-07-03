// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/



import java.util.*;

class Solution {
    public int minDifference(int[] nums) {
        // return approach_1(nums);

        return approach_2(nums);
    }

    // TC : O(N*log(N))
    // SC : O(1)
    private static int approach_1(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        if (n <= 3) return 0;

        int result = Integer.MAX_VALUE;
        result = Math.min(result, nums[n - 4] - nums[0]);
        result = Math.min(result, nums[n - 3] - nums[1]);
        result = Math.min(result, nums[n - 2] - nums[2]);
        result = Math.min(result, nums[n - 1] - nums[3]);
        return result;
    }

    // TC : O(N) : Using Partial Sorting
    // SC : O(1)
    private static int approach_2(int[] nums) {
        int n = nums.length;
        if (n <= 4) {
            return 0;
        }

        // Find the four smallest elements using a fixed-size max heap
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(
            Collections.reverseOrder()
        );
        for (int num : nums) {
            maxHeap.offer(num);
            if (maxHeap.size() > 4) {
                maxHeap.poll();
            }
        }
        List<Integer> smallestFour = new ArrayList<>(maxHeap);
        Collections.sort(smallestFour);

        // Find the four largest elements using a fixed-size min heap
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int num : nums) {
            minHeap.offer(num);
            if (minHeap.size() > 4) {
                minHeap.poll();
            }
        }
        List<Integer> largestFour = new ArrayList<>(minHeap);
        Collections.sort(largestFour);

        int minDiff = Integer.MAX_VALUE;
        // Four scenarios to compute the minimum difference
        for (int i = 0; i < 4; i++) {
            minDiff = Math.min(
                minDiff,
                largestFour.get(i) - smallestFour.get(i)
            );
        }

        return minDiff;
    }
}