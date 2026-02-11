// https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1/




import java.util.*;

class Solution {
    public int minCost(int[] heights, int[] cost) {
        int low = Arrays.stream(heights).min().getAsInt(); 
        int high = Arrays.stream(heights).max().getAsInt();
        int ans = high;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int v1 = getCost(heights, cost, mid);
            int v2 = getCost(heights, cost, mid + 1);
            if (v1 <= v2) {
                ans = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return getCost(heights, cost, ans);
    }
    private static int getCost(int[] heights, int[] cost, int tar) {
        int totalCost = 0;
        for (int i = 0; i < heights.length; i ++) {
            totalCost += Math.abs(tar - heights[i]) * cost[i];
        }
        return totalCost;
    }
}