// https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1




import java.util.*;

class Solution {
    // TC : O(N * log(max(heights) - min(heights)))
    // SC : O(1)
    public int minCost(int[] heights, int[] cost) {
        int n = heights.length;
        int low  = Arrays.stream(heights).min().getAsInt();
        int high = Arrays.stream(heights).max().getAsInt();
        int ans  = high;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int v1  = getTotalCost(heights, cost, n, mid);
            int v2  = getTotalCost(heights, cost, n, mid + 1);
            if (v1 <= v2) {
                ans  = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return getTotalCost(heights, cost, n, ans);
    }
    private int getTotalCost(int[] heights, int[] cost, int n, int tar) {
        int totalCost = 0;
        for (int i = 0; i < n; i ++) {
            totalCost += (Math.abs(heights[i] - tar) * cost[i]);
        }
        return totalCost;
    }
}
